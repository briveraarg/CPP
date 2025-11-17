# Tema del módulo 03: Inheritance

Este módulo trata sobre cómo una clase puede heredar de otra, compartiendo sus atributos y comportamientos, y cómo extenderlos o modificarlos.

## Nota sobre ex00 - ClapTrap

- Clase implementada: `ClapTrap` (archivo `ex00/ClapTrap.hpp` / `ClapTrap.cpp`).
- Atributos clave: `name`, `hitPoints` (inicial 10), `energyPoints` (inicial 10), `attackDamage` (inicial 0).
- Constructores: se incluyen constructor por defecto, constructor con `name` y constructor de copia. Además se implementó operador= y destructor (Rule of Three).
- Mensajes: se añadieron mensajes informativos en constructores, destructor y en los métodos `attack`, `takeDamage`, `beRepaired` para facilitar la validación manual.
- Seguridad: se añadió comprobación para evitar underflow cuando se resta daño a `hitPoints` (si `amount >= hitPoints` se deja en 0).
- Colores: el proyecto usa macros ANSI para colorear la salida opcionalmente; se recomienda usarlos usando `<< BRIGHT_BLUE << name << RESET <<` (no concatenarlos como literales adyacentes).
- Tests: `ex00/main.cpp` contiene pruebas manuales que ejercitan ataques, reparación, agotamiento de energía, muerte y copia/assign.

### ¿Por qué 3 constructores?

Constructor por defecto (ClapTrap()): crea un objeto con valores iniciales por defecto (útil cuando no conoces el nombre o para crear arrays/containers).
Constructor parametrizado (ClapTrap(const std::string &name)): te permite crear una instancia con un nombre específico.
Constructor de copia (ClapTrap(const ClapTrap &other)): define cómo se copia un objeto a otro (necesario para copias correctas de estado).
Esto encaja con la llamada "Rule of Three" en C++98: si implementas manualmente cualquiera de (destructor, constructor de copia, operador=), normalmente debes implementar los otros dos. En tu código tienes también el operador= y el destructor, así que estás respetando la regla.

# Notas sobre el ex01 (ejercicio ClapTrap / ScavTrap)

1) Relación IS-A (Herencia)
- Cuando declares `class ScavTrap : public ClapTrap` decimos que "ScavTrap es un ClapTrap" (IS-A). El subobjeto `ClapTrap` forma parte del objeto `ScavTrap`.
- Por eso puedes usar un `ScavTrap` donde se espere un `ClapTrap*` o `ClapTrap&` (conversión implícita derivado→base).

2) Punteros/Referencias vs Objetos por valor
- `ClapTrap* p = new ScavTrap("G");` almacena la dirección del objeto `ScavTrap` en un puntero a la base `ClapTrap*`.
- `ClapTrap c = ScavTrap("G");` provoca slicing: se copia sólo la parte `ClapTrap` en `c` y se pierde la parte derivada `ScavTrap`.
- Usar referencias (`ClapTrap& r = s;`) permite acceder al objeto derivado sin slicing.

3) Polimorfismo y `virtual`
- Declarar un método en la base como `virtual` (por ejemplo `virtual void attack(...)`) permite que llamadas realizadas a través de punteros/referencias a la base ejecuten la implementación de la clase derivada en tiempo de ejecución.
- Esto es imprescindible si quieres escribir código genérico que trate objetos distintos a través de la interfaz base (
	p.ej. contenedores de `ClapTrap*` que almacenen `ScavTrap*`, `FragTrap*`, etc.).

4) Destructor virtual
- Si vas a borrar objetos derivados a través de punteros a la base (`delete p` donde `p` es `ClapTrap*` apuntando a un `ScavTrap`), el destructor de la base debe ser `virtual`.
- Si `~ClapTrap()` no es virtual, `delete p` desencadena comportamiento indefinido: el destructor derivado no se llamará y podrías provocar fugas o estados inconsistentes.

5) Orden de construcción y destrucción
- Construcción: primero se construyen los subobjetos base (ClapTrap), luego los miembros directos de la clase derivada (ScavTrap), y finalmente se ejecuta el cuerpo del constructor derivado.
- Destrucción: orden inverso — primero el cuerpo del destructor derivado, luego el destructor base.

6) Inicialización de miembros y lista de inicializadores
- En la lista de inicializadores del constructor de `ScavTrap` puedes inicializar:
	- subobjetos base: `ScavTrap(): ClapTrap("name") {}`
	- miembros declarados en `ScavTrap` (ej: `_specialFlag(true)`).
- No puedes inicializar directamente miembros declarados en la clase base (ej: `_hitPoints`) desde la lista de inicializadores de `ScavTrap` — esos deben inicializarse por el constructor de `ClapTrap`.
- Si quieres establecer valores concretos en la parte base, la opción idiomática es añadir un constructor parametrizado en `ClapTrap` que reciba (name, hp, ep, ad) y llamarlo desde `ScavTrap`.

7) Rule of Three (copiar/assign/destruir)
- Cuando implementas destructor, copia u operador= manualmente, debes considerar los tres. Esto es importante si tu clase gestiona recursos (memoria dinámica, handles, etc.).
- En este ejercicio, ClapTrap implementa los tres para controlar mensajes y copia de estado simple.

8) Slicing (corte)
- `ClapTrap c = ScavTrap("G");` compila porque hay un constructor de copia/convertidor desde `ScavTrap` a `ClapTrap` implícito, pero el objeto resultante `c` es sólo la parte base. Evita hacerlo si necesitas el comportamiento derivado.

9) Conversión de punteros y ajustes (offsets)
- En herencia simple, la dirección del subobjeto base suele coincidir con la dirección del objeto derivado (offset 0), por eso `ClapTrap* p = s` donde `s` es `ScavTrap*` apunta al mismo bloque de memoria.
- En herencia múltiple/virtual, el compilador puede ajustar el puntero (añadir offset). El ajuste lo realiza el compilador en la conversión implícita.

10) vptr / vtable (muy breve)
- Los métodos virtuales usan una tabla de despacho (vtable). Cada objeto que tiene métodos virtuales suele contener un puntero implícito (vptr) a esa tabla.
- La vtable permite resolver qué implementación concreta ejecutar en tiempo de ejecución.

11) Administración de memoria: `new` / `delete`
- `new ScavTrap("G")` reserva memoria en el heap y llama a los constructores. `delete p` invoca el destructor correspondiente y libera memoria.
- En C++98 no hay smart pointers en la librería estándar; gestiona `delete` manualmente o evita `new` cuando sea posible (usar objetos en pila y referencias).

12) Buenas prácticas aplicadas en el ejercicio
- Hicimos miembros `protected` en `ClapTrap` cuando la derivada necesitaba acceder/ajustar valores iniciales.
- Hicimos `attack` `virtual` para que `ScavTrap::attack` se ejecute a través de punteros/referencias a la base.
- Hicimos `~ClapTrap` `virtual` para asegurar destrucción correcta.
- Añadimos comprobaciones defensivas (HP/EP) para evitar underflow en unsigned ints.

13) Ejemplos de uso y efectos en `main.cpp`
- `ClapTrap* p = new ScavTrap("Guardian"); p->attack("x"); delete p;` demuestra polimorfismo y destructores virtuales.
- `ClapTrap c = ScavTrap("G");` demuestra slicing (pérdida de la parte derivada).
- `ClapTrap& r = s;` (referencia) evita slicing y permite polimorfismo.

14) Posibles mejoras/extensiones
- Añadir un constructor parametrizado en `ClapTrap` para inicializar hp/ep/ad desde la lista de inicializadores en `ScavTrap`.
- Implementar `_guardMode` booleano en `ScavTrap` para que `guardGate()` cambie estado en vez de sólo imprimir.
- Agregar getters `getHitPoints()` / `getEnergyPoints()` para depuración y pruebas.
- En C++ moderno, usar `std::unique_ptr<ClapTrap>` en lugar de `new`/`delete`.

15) Resumen práctico (qué recordar)
- Usa punteros/referencias para polimorfismo; no uses copia por valor si quieres preservar comportamiento derivado.
- Declara destructor virtual en la clase base si hay herencia y borrado por puntero a la base.
- Inicializa la parte base en la lista de inicializadores llamando al constructor de la base cuando necesites establecer valores concretos de la base.

---

## ex03 - DiamondTrap: conceptos teóricos y práctica (sombreado de nombre y banderas -Wshadow)

Esta sección recoge los conceptos teóricos adicionales requeridos por el ejercicio **ex03** (DiamondTrap), y una explicación práctica sobre las banderas del compilador `-Wshadow` y `-Wno-shadow`.

/* Resumen: qué pide el ejercicio */
- `DiamondTrap` hereda de `FragTrap` y `ScavTrap` (ambos derivados de `ClapTrap`).
- `DiamondTrap` debe mantener su propio atributo `_name` (el mismo identificador que usa `ClapTrap`).
- La parte `ClapTrap` debe inicializarse con `name + "_clap_name"`.
- `DiamondTrap::whoAmI()` debe imprimir tanto el `_name` de `DiamondTrap` como el `_name` del `ClapTrap` base.
- `DiamondTrap::attack()` delega la implementación a `ScavTrap::attack()`.

/* Puntos clave de diseño y por qué se hacen así */
1) Herencia virtual
- Cuando `FragTrap` y `ScavTrap` heredan de `ClapTrap` y después `DiamondTrap` hereda de ambos, se crea un "diamante" de herencia. Si no se usa herencia virtual, `ClapTrap` existiría dos veces dentro de `DiamondTrap` (doble subobjeto base), lo que causa duplicación de estado y ambigüedad.
- Solución: declarar `class FragTrap : virtual public ClapTrap` y `class ScavTrap : virtual public ClapTrap`. Con herencia virtual hay un único subobjeto `ClapTrap` compartido por todas las ramas del diamante.

2) Orden de construcción y destrucción (con herencia virtual)
- Construcción: primero se construye el (único) subobjeto virtual `ClapTrap` (inicializado por la clase más derivada que lo menciona en su lista de inicialización — en este caso `DiamondTrap` cuando llame a `ClapTrap(name + "_clap_name")`), luego se construyen los subobjetos no virtuales (`ScavTrap`, `FragTrap`) y finalmente el cuerpo de `DiamondTrap`.
- Destrucción: orden inverso — cuerpo de `DiamondTrap`, luego destructores de `FragTrap`/`ScavTrap`, y por último el destructor de `ClapTrap`.

3) Sombreado (name shadowing)
- El ejercicio pide explícitamente que `DiamondTrap` tenga su propio miembro llamado `_name` que *sombreará* (shadow) el miembro `_name` heredado desde `ClapTrap`.
- Esto es intencional: `DiamondTrap::_name` contiene por ejemplo `"Iria"` y `ClapTrap::_name` contiene `"Iria_clap_name"`.
- En C++ el hecho de declarar un miembro con el mismo nombre en la clase derivada es válido, pero el compilador puede avisar con la advertencia `-Wshadow`.

4) Acceso a ambos nombres
- Para distinguirlos en el código usa la resolución de alcance explícita:
	- `this->_name` o `DiamondTrap::_name` para el nombre de `DiamondTrap`.
	- `ClapTrap::_name` para acceder al nombre que vive en la subparte `ClapTrap`.

5) Polimorfismo y métodos virtuales
- W para que `ClapTrap` declare `virtual void attack(const std::string &target);` y `virtual ~ClapTrap();` para garantizar que:
	- Llamadas a `attack` a través de punteros/referencias a la base llamen la versión correcta en tiempo de ejecución.
	- Borrar (`delete p`) un objeto derivado a través de un puntero `ClapTrap*` invoque correctamente los destructores derivados.

6) Por qué `DiamondTrap::attack` delega a `ScavTrap::attack()`
- El enunciado pide que `DiamondTrap` utilice la implementación de ataque de `ScavTrap`. Implementar `DiamondTrap::attack()` como `ScavTrap::attack(target);` o `ScavTrap::attack(static_cast<ScavTrap&>(*this), target);` (forma simple: `ScavTrap::attack(target);`) consigue ese objetivo.

/* -Wshadow y -Wno-shadow: explicación práctica */

1) ¿Qué hace `-Wshadow`?
- `-Wshadow` es una advertencia del compilador (g++/clang) que informa cuando una variable local, un parámetro, o un miembro en una clase derivada tiene el mismo nombre que otra variable en un ámbito más externo (por ejemplo una variable global, un miembro de la clase base, o una variable en un scope externo). Es útil para detectar errores accidentales donde un identificador oculta otro por error.

2) ¿Qué hace `-Wno-shadow`?
- `-Wno-shadow` desactiva esa advertencia. Útil cuando el sombreado es intencional y quieres mantener el código tal como está sin ensuciar la salida de compilación con avisos.

3) Ejemplos prácticos de compilación
- Compilar con advertencias estrictas (recomendado durante desarrollo):

```bash
g++ -Wall -Wextra -Wshadow -std=c++98 -o diamond main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
```

- Si el sombreado es intencional y quieres silenciar sólo esa advertencia para una compilación concreta:

```bash
g++ -Wall -Wextra -Wno-shadow -std=c++98 -o diamond main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
```

4) Recomendaciones de buenas prácticas
- Si el ejercicio **requiere** usar exactamente el mismo nombre (como `DiamondTrap::_name`), la mejor opción es **mantener el nombre**, documentar claramente la intención (comentario en el código y en el `WikiNotas.md`) y dejar `-Wshadow` activado durante el desarrollo para detectar *otros* shadowings accidentales, pero silenciarlo sólo cuando sea necesario (`-Wno-shadow`) o mediante `#pragma` en archivos concretos.
- Alternativas:
	- Renombrar el miembro derivado (p. ej. `_diamondName`) para eliminar la advertencia — sencillo pero puede violar la intención del ejercicio.
	- Usar un `#pragma` local en el archivo para desactivar `-Wshadow` sólo ahí (solución específica del compilador; portable entre gcc/clang con pragmas condicionales).

5) Ejemplo de `#pragma` (gcc/clang) — poner en `DiamondTrap.cpp` sólo si quieres suprimir la advertencia localmente:

```cpp
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wshadow"
#endif

// ... código que provoca shadowing intencional ...

#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif
```

/* Ejemplo breve (ilustrativo) */
```cpp
// En DiamondTrap.hpp
class DiamondTrap : public ScavTrap, public FragTrap {
public:
		DiamondTrap(const std::string &name);
		void whoAmI();
private:
		std::string _name; // intentional shadow of ClapTrap::_name
};

// En DiamondTrap.cpp
void DiamondTrap::whoAmI() {
		std::cout << "I am " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
```

/* Conclusión práctica */
- Para el propósito del ejercicio: mantén el sombreado, documenta la intención (ya está en `DiamondTrap.hpp` y ahora también en `WikiNotas.md`) y compila con `-Wextra -Wall` durante el desarrollo. Si `-Wshadow` genera ruido inesperado por este caso intencional, añade `-Wno-shadow` en la línea de compilación o usa un `#pragma` local si prefieres una supresión localizada.

---



Esta sección recoge las decisiones y conceptos para la clase `FragTrap` (ejercicio ex02), que hereda de `ClapTrap`.

1) Propósito

2) Declaración típica
```cpp
class FragTrap : public ClapTrap
{
public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void highFivesGuys(); // método especial de FragTrap
};
```

3) Estadísticas sugeridas

Estas cifras son las usadas históricamente en el ejercicio y permiten distinguir `FragTrap` de `ClapTrap` y `ScavTrap`.

4) Inicialización correcta
	- Asignar en el cuerpo del constructor de `FragTrap` (válido y sencillo).
	- Mejor: añadir en `ClapTrap` un constructor parametrizado (name, hp, ep, ad) y llamar a ese constructor desde la lista de inicializadores de `FragTrap` para inicializar la parte base correctamente.

Ejemplo (opción intermedia — asignación en cuerpo):
```cpp
FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
		this->_hitPoints = 100;
		this->_energyPoints = 100;
		this->_attackDamage = 30;
		std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}
```

5) Método especial

6) Polimorfismo y buenas prácticas

7) Ejemplo de uso en `main` (ex02)
```cpp
FragTrap f("Freddie");
f.attack("target");
f.highFivesGuys();

ClapTrap *p = new FragTrap("F2");
p->attack("foe"); // si virtual -> FragTrap::attack o ClapTrap::attack según implementación
delete p; // destructor virtual en la base garantiza llamada correcta
```


Perfecto, acá tenés un **apunte corto, claro y perfecto para tu .md** sobre constructores eficientes aplicados a *ClapTrap → ScavTrap → FragTrap → DiamondTrap*.
Todo compacto y pensado para estudiar.

---

# 📘 Apunte: Constructores eficientes en el Módulo 03

En C++, la forma más eficiente de crear objetos es **inicializando** los atributos directamente en la *lista de inicialización del constructor*.
Esto evita trabajo innecesario y asegura que los objetos padres se construyan correctamente.

---

# 🟦 1. ¿Por qué usar listas de inicialización?

### Inicialización (eficiente)

El objeto se construye **directamente** con los valores correctos.

### Asignación (menos eficiente)

Primero se construye con valores por defecto → luego se reasigna → doble trabajo.

➡️ **Regla de oro:** *Todo lo que se pueda inicializar, se inicializa en la lista.*

---

# 🟦 2. Ejemplo general

```cpp
Class::Class(int x) : _value(x)   // Inicialización
{
    // Código extra
}
```

vs

```cpp
Class::Class(int x)
{
    _value = x;                   // Asignación → menos eficiente
}
```


Exacto, **la forma REALMENTE eficiente es esta**:

```cpp
FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << BOLD << this->_name
			  << RESET << " constructor called" << std::endl;
}
```

## ✅ ¿Por qué esta es la versión más eficiente?

Porque **inicializás absolutamente todo directamente en la lista de inicialización**, incluyendo:

* `_name`
* `_hitPoints`
* `_energyPoints`
* `_attackDamage`

Esto significa:

❌ No hay asignaciones posteriores
❌ No hay sobreescritura de valores por defecto
❌ No hay trabajo duplicado
❌ No hay inicialización seguida de reasignación

✔️ ClapTrap recibe **todo lo que necesita** y lo deja listo en un solo paso.

---

## Comparación clara (para tu .md)

### ❌ Menos eficiente

```cpp
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name)
{
    this->_hitPoints = 100;      // Asignación (2 pasos)
    this->_energyPoints = 100;   // Asignación (2 pasos)
    this->_attackDamage = 30;    // Asignación (2 pasos)
}
```

Problema:
ClapTrap inicializa primero con valores por defecto → después vos reasignás → se hizo doble trabajo.

---

### ✅ Más eficiente (ideal)

```cpp
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap " << this->_name << " constructor called\n";
}
```

Ventajas:

✔️ Todo se inicializa de una sola vez
✔️ ClapTrap ya nace con los valores correctos
✔️ No se reasigna nada
✔️ Código más limpio y claro

---

## ✨ Regla de oro resumen

> **Lo que puedas inicializar en la lista de inicialización → HACÉLO ahí.
> Lo que dejes para el cuerpo del constructor → solo si no hay otra opción.**

---

Si querés, te hago un **apunte corto basado en esta mejora** exclusivamente para FragTrap, ScavTrap y DiamondTrap.

---

# 🟦 3. Aplicación en el módulo: ClapTrap → Herencias

Para maximizar eficiencia, **los valores deben llegar ya correctos al constructor del padre**.

---

# 🟩 ClapTrap

Constructor con parámetros:

```cpp
ClapTrap::ClapTrap(const std::string& name, unsigned int hp,
                   unsigned int ep, unsigned int ad)
    : _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
    std::cout << "ClapTrap " << _name << " custom constructor\n";
}
```

---

# 🟦 ScavTrap (HP=100, EP=50, AD=20)

```cpp
ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << _name << " constructor\n";
}
```

✔️ Todo inicializado en un solo lugar (ClapTrap).
✔️ Nada que reasignar en el cuerpo.

---

# 🟪 FragTrap (HP=100, EP=100, AD=30)

```cpp
FragTrap::FragTrap(const std::string &name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap " << _name << " constructor\n";
}
```

✔️ El más eficiente (sin asignaciones después).

---

# 🟧 DiamondTrap (doble herencia)

DiamondTrap tiene dos nombres:

* `_name` propio
* `ClapTrap::_name` → debe ser `name + "_clap_name"`

### Constructor eficiente:

```cpp
DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name", 100, 50, 30),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    std::cout << "DiamondTrap " << _name << " constructor\n";
}
```

✔️ ClapTrap nace **directamente** con HP, EP y AD correctos
✔️ `_name` propio queda separado
✔️ No hay reasignaciones internas

---

# 🟦 4. Resumen final (para la memoria)

* **Usá parámetros en la lista de inicialización cuando se pueda.**
* **Constructores de las clases base deben llamarse en la lista.**
* **Nada de asignar HP/EP/AD dentro del cuerpo si se pueden pasar por constructor.**
* **DiamondTrap debe inicializar ClapTrap con `<name>_clap_name`.**

---

Si querés, te preparo también un apunte igual de corto sobre:

🟦 *Regla de los 4 (forma canónica en C++)*
🟦 *Orden de construcción en herencia múltiple*
🟦 *Qué hace el compilador por defecto en cada constructor*

¡Vos decime!




