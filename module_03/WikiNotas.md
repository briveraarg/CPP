
# 🚀 C++ Módulo 03: Inheritance (Herencia)

Este módulo trata sobre cómo una clase puede heredar de otra, compartiendo atributos y comportamientos (Relación "IS-A"), y cómo extenderlos o modificarlos sin romper todo.

-----

## 🟢 ex00: ClapTrap (La Base)

El abuelo de todos. Aquí definimos la estructura básica y la gestión de memoria manual.

### 📋 Checklist de Implementación

  * **Archivos:** `ClapTrap.hpp` / `ClapTrap.cpp`
  * **Atributos:** `name`, `hitPoints` (10), `energyPoints` (10), `attackDamage` (0).
  * **Seguridad:**
      * Evitar *underflow* en `hitPoints` (si `amount >= hitPoints`, queda en 0).
      * Chequear energía antes de atacar.
  * **Colores:** Usar macros ANSI. *Tip: No concatenar literales con macros, usá `<< COLOR << variable << RESET`.*

### 🛠️ Rule of Three (La Regla de los Tres)

Si implementás manualmente uno, probablemente necesites los otros dos. En este *ex* tenés memoria dinámica o mensajes específicos, así que implementamos:

1.  **Destructor:** (`~ClapTrap`) Para limpiar o avisar que murió.
2.  **Constructor de Copia:** (`ClapTrap(const ClapTrap &other)`) Para copiar el estado correctamente.
3.  **Operador de Asignación:** (`operator=`) Para pasar valores de un objeto ya existente a otro.

### 💡 ¿Por qué 3 constructores?

1.  **Default:** `ClapTrap()` → Útil para arrays o contenedores donde no sabés el nombre todavía.
2.  **Parametrizado:** `ClapTrap(string name)` → La forma normal de instanciarlo.
3.  **Copy Constructor:** `ClapTrap(const ClapTrap &other)` → Esencial para evitar copias superficiales (shallow copies) si hubiera punteros.

-----

## 🟡 ex01: ScavTrap (Herencia Simple & Virtual)

Aquí entra la magia de `class ScavTrap : public ClapTrap`.

### 🧠 Conceptos Clave

#### 1\. Relación IS-A

  * "ScavTrap **es un** ClapTrap".
  * Podés usar un `ScavTrap` en cualquier función que pida un `ClapTrap*` o `ClapTrap&`.

#### 2\. Slicing (El Corte) 🔪

  * ⚠️ **Cuidado:** `ClapTrap c = ScavTrap("G");`
  * Esto **corta** la parte de ScavTrap y se queda solo con la base. Perdemos los datos del hijo.
  * ✅ **Solución:** Usar punteros (`ClapTrap*`) o referencias (`ClapTrap&`) para mantener el polimorfismo.

#### 3\. Destructor Virtual (¡CRÍTICO\!)

Si tenés un puntero a la base apuntando a un hijo:

```cpp
ClapTrap* p = new ScavTrap("Guardian");
delete p; // ¿Qué destructor se llama?
```

  * Si `~ClapTrap()` **NO** es `virtual`: Solo se borra la base. **Memory Leak** seguro.
  * Si `~ClapTrap()` **ES** `virtual`: Se llama primero al destructor del hijo (`~ScavTrap`) y luego al del padre.

#### 4\. Orden de Vida

  * **Nacimiento:** Base (ClapTrap) → Derivada (ScavTrap).
  * **Muerte:** Derivada (ScavTrap) → Base (ClapTrap).

-----

## 🟠 ex02: FragTrap (Eficiencia en Constructores)

FragTrap es similar a ScavTrap pero con stats diferentes y el método `highFivesGuys()`. Aquí es donde nos ponemos serios con la **eficiencia**.

### ⚡ La Regla de Oro de la Inicialización

> **"Todo lo que se pueda inicializar en la lista de inicialización, se hace ahí."**

No pierdas tiempo construyendo al padre con valores *default* para después sobreescribirlos en el cuerpo del hijo.

### ❌ Forma Ineficiente (Asignación)

```cpp
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) // Llama al constructor básico
{
    // Trabajo doble: se crearon con default y ahora los pisamos
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}
```

### ✅ Forma Eficiente (Inicialización Directa)

Para esto, `ClapTrap` debe tener un constructor que acepte todos los stats (ver sección final).

```cpp
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 30) // ¡Boom! Nace perfecto
{
    std::cout << "FragTrap constructed efficiently.\n";
}
```

-----

## 🔴 ex03: DiamondTrap (Herencia Múltiple y Virtual)

El monstruo final. `DiamondTrap` hereda de `ScavTrap` y `FragTrap`.

### 💎 El Problema del Diamante

Si `ScavTrap` y `FragTrap` heredan de `ClapTrap` normalmente, `DiamondTrap` tendría **dos copias** de `ClapTrap` adentro. Ambigüedad total.

**Solución: Herencia Virtual**

```cpp
class ScavTrap : virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
```

Esto garantiza que solo exista **una única instancia** de `ClapTrap` compartida en memoria.

### 🌑 Shadowing (Sombreado de Variables)

El ejercicio pide que `DiamondTrap` tenga su propio `_name` privado, ocultando el `_name` de `ClapTrap`.

  * **Acceso:**
      * `this->_name` → Nombre del DiamondTrap.
      * `ClapTrap::_name` → Nombre de la base (que debe ser `name + "_clap_name"`).

### ⚠️ Banderas del Compilador: `-Wshadow`

El compilador te va a gritar porque estás ocultando una variable.

  * **Desarrollo:** Usá `-Wshadow` para ver si metiste la pata en otro lado.
  * **Entrega:** Si el ejercicio obliga a hacer shadowing, podés usar `-Wno-shadow` o documentar que es intencional.

### 🏗️ Constructor del Diamond (La prueba de fuego)

Debemos inicializar la base virtual `ClapTrap` explícitamente, y luego llamar a los padres intermedios.

```cpp
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name", 100, 50, 30), // Init Base Virtual
      ScavTrap(name),                             // Init Padre 1
      FragTrap(name),                             // Init Padre 2
      _name(name)                                 // Init Propio
{
    this->_energyPoints = 50; // ScavTrap define EP
    std::cout << "DiamondTrap constructor.\n";
}
```

*Nota: Los stats se toman de FragTrap (HP/AD) y ScavTrap (EP), según el subject.*

-----

## 🎓 Apunte Extra: Guía de Constructores Eficientes

Para que tu código sea "Pro", modificá `ClapTrap` para permitir la inyección directa de stats.

### 1\. En ClapTrap (El Padre)

```cpp
// Constructor protegido o público que recibe todo
ClapTrap::ClapTrap(std::string name, int hp, int ep, int ad)
    : _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
    std::cout << "ClapTrap custom constructor called\n";
}
```

### 2\. En ScavTrap

```cpp
ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, 100, 50, 20) // Pasamos los valores fijos aquí
{
    std::cout << "ScavTrap constructor\n";
}
```

### 3\. En FragTrap

```cpp
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap constructor\n";
}
```

-----

### ✅ Resumen Rápido para la Defensa

1.  **Polimorfismo:** Usar siempre `virtual` en el destructor base y métodos como `attack`.
2.  **Memoria:** Si usás `new`, acordate del `delete`. El destructor virtual salva vidas.
3.  **Slicing:** Pasá objetos por referencia (`&`) o puntero (`*`), nunca por valor si querés mantener la parte derivada.
4.  **Eficiencia:** ¡Usá las listas de inicialización\!
5.  **Diamond:** Requiere herencia virtual (`virtual public`) para no duplicar al abuelo `ClapTrap`.

-----

**¿Te gustaría que genere un `main.cpp` de prueba que integre todas las clases para verificar el tema del Diamond y el Shadowing?**