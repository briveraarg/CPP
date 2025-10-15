### Resumen (Basado en el Ejercicio)

El ejercicio busca a crear dos escenarios distintos:

1.  **`newZombie(std::string name)` -> Usa Heap**
2.  **`randomChump(std::string name)` -> Usa Stack**

La razón es demostrar la diferencia fundamental en la **vida útil** del objeto.

---

### ¿Cuándo es Mejor Stack? -> Caso de `randomChump`

```cpp
// randomChump.cpp
#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie(name); 
    zombie.announce();

    // Fin de la función: el destructor de `zombie` se llama AUTOMÁTICAMENTE aquí.
    // Se imprime el mensaje de destrucción.
}
```

*   **¿Por qué la STACK?** Porque el zombi de `randomChump` es un objeto **temporal y de un solo uso**. Su único propósito es anunciarse y luego "morir" (ser destruido) inmediatamente cuando la función termina.
*   **Ventaja:** La gestión de memoria es **automática y segura**. No hay forma de que se te olvide liberar la memoria, evitando *memory leaks*.
*   **Caso de uso ideal:** Para objetos de vida muy corta, que solo son necesarios dentro del ámbito de una función o un bloque de código.

**En resumen: Usa STACK cuando el objeto no necesite existir después de que la función haya terminado.**

---

### ¿Cuándo es Mejor el Heap? -> Caso de `newZombie`

```cpp
// newZombie.cpp
#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name); // Creación en el Heap
    return zombie; // Devuelve el puntero al zombi que sigue VIVO en el heap
}
```

```cpp
// main.cpp (Ejemplo de uso)
int main() {
    // El zombi creado por newZombie vive después de la función
    Zombie* heapZombie = newZombie("Gloria");
    heapZombie->announce();

    // ... puedes usar heapZombie en otras partes del main o pasarlo a otras funciones ...

    // ¡IMPORTANTE! Debemos destruirlo manualmente cuando ya no lo necesitemos.
    delete heapZombie; // Sin este 'delete', hay memory leak.
    return 0;
}
```

*   **¿Por qué el Heap?** Porque la función `newZombie` debe **devolver el zombi** para que se pueda usar **fuera del ámbito de la función**. Un objeto en STACK sería destruido al terminar `newZombie`, haciendo que el puntero devuelto apunte a memoria inválida (comportamiento indefinido).
*   **Ventaja:** Te da **control sobre la vida útil** del objeto. El zombi puede "sobrevivir" a la función que lo creó y ser usado en otra parte del programa.
*   **Desventaja:** La gestión de memoria es **manual**. Tú eres responsable de llamar a `delete` para evitar fugas de memoria.
*   **Caso de uso ideal:** Para objetos que deben persistir después de que la función que los crea haya terminado, o cuando necesitas crear muchos objetos cuyo número no conoces hasta el tiempo de ejecución (como una horda de zombis).

**En resumen: Usa el Heap cuando el objeto deba seguir existiendo después de que la función que lo crea haya finalizado.**

---

### Tabla de Decisión para el Ejercicio

| Función | Memoria | ¿Por qué? | Responsabilidad de Destrucción |
| :--- | :--- | :--- | :--- |
| **`randomChump`** | **STACK (Stack)** | El zombi es temporal, solo anuncia y muere. Su vida termina con la función. | **Automática**. El destructor se llama solo. |
| **`newZombie`** | **Heap** | El zombi debe ser devuelto y usado **fuera** de la función donde se crea. | **Manual**. Tú debes llamar a `delete` cuando ya no lo necesites. |

### Conclusión Final del Ejercicio

El **"punto real del ejercicio"** es demostrar de manera práctica la diferencia crítica entre el *tiempo de vida* de un objeto en STACK vs. en el Heap.

*   **`randomChump`** te muestra la **conveniencia y seguridad** de STACK para objetos temporales.
*   **`newZombie`** te muestra la **flexibilidad y control** del Heap para objetos de larga duración, junto con la **responsabilidad** que esto conlleva (el `delete`).

**La elección correcta depende de una sola pregunta: ¿Necesito que este zombi siga vivo después de que termine la función en la que lo creo?**
*   **No ->** STACK (`randomChump`).
*   **Sí ->** Heap (`newZombie`).

---

## Ejercicio 01: "Moar brainz!" - Arrays de Zombies

### Objetivo
Crear una **horda completa de zombies** usando una **sola asignación de memoria** en el heap.

### Función Principal: `zombieHorde`
```cpp
Zombie* zombieHorde(int N, std::string name);
```

### ¿Qué hace?
1. **Asigna memoria para N zombies de una vez:** `new Zombie[N]`
2. **Inicializa cada zombie** con el mismo nombre usando `setName()`
3. **Retorna puntero al primer zombie** del array

### Diferencias Clave con el Ejercicio 00

| Aspecto | Ejercicio 00 | Ejercicio 01 |
|---------|--------------|--------------|
| **Memoria** | `new Zombie(name)` - UN zombie | `new Zombie[N]` - N zombies |
| **Liberación** | `delete zombie` | `delete[] horde` |
| **Asignaciones** | Una por zombie | UNA para todos |
| **Constructor** | `Zombie(name)` - con parámetro | `Zombie()` - por defecto |
| **Inicialización** | Automática en constructor | Manual con `setName()` |

### Proceso Paso a Paso

#### 0. Concepto de sobrecarga de constructores 

```cpp
Zombie();
Zombie(std::string name);
```

Son **dos constructores distintos** —uno **por defecto** (sin parámetros) y otro **parametrizado** (con nombre). Esto se llama **sobrecarga de constructores**.
En ese momento, el compilador **crea N objetos Zombie** **sin argumentos**, o sea que necesita llamar a `Zombie()` para cada uno.
Si no existe ese constructor, **no puede crear el array** y da error.

---

### ✅ En resumen

| Constructor                | Cuándo se usa      | Por qué es necesario                                  |
| -------------------------- | ------------------ | ----------------------------------------------------- |
| `Zombie()`                 | `new Zombie[N]`    | Se necesita un constructor sin argumentos para arrays |
| `Zombie(std::string name)` | `Zombie("Brenda")` | Para inicializar zombies individuales con nombre      |

---

Así que sí:

* tiene un fin técnico (el array necesita el constructor vacío),
* **y también pedagógico** (entender la sobrecarga y la inicialización en C++).

¿Querés que te muestre un ejemplo corto donde se usan los dos en la práctica (como en el módulo *Zombie horde*)?

#### 1. Creación del Array
```cpp
Zombie* horde = new Zombie[5];  // Crea 5 zombies
```
- C++ llama automáticamente al **constructor por defecto** 5 veces
- Cada zombie se crea con `name = ""` (vacío)

```cpp
Zombie* horde = new(std::nothrow) Zombie[N]; 
// Crea 5 zombies. Si la reserva de memoria falla, normalmente el operador new lanza una excepción del tipo std::bad_alloc. 
//std::nothrow Es un modificador que le dice a new: “Si no hay suficiente memoria, no lances una excepción. En su lugar, devolvé nullptr.”

#### 2. Asignación de Nombres
```cpp
while (i < N)
{
    horde[i].setName(name);  // Asigna "Jorge" a cada zombie
    i++;
}
```
- **¿Por qué `setName()`?** Porque no podemos pasar parámetros a `new Zombie[N]`
- Todos los zombies terminan con el mismo nombre

#### 3. Uso del Array
```cpp
horde[0].announce();  // Jorge: BraiiiiiiinnnzzzZ...
horde[1].announce();  // Jorge: BraiiiiiiinnnzzzZ...
// etc.
```

#### 4. Liberación de Memoria
```cpp
delete[] horde;  // ¡IMPORTANTE! Los [] son obligatorios para arrays
horde = nullptr; // Buena práctica
```

### Conceptos Importantes

#### ¿Por qué Constructor por Defecto?
```cpp
class Zombie {
public:
    Zombie();              // ¡NECESARIO para arrays!
    Zombie(std::string);   // Para objetos individuales
    void setName(std::string name);  // Para arrays
};
```
- **Arrays necesitan constructor sin parámetros**
- **`new Zombie[N](param)` NO existe en C++**

#### Una Sola Asignación vs Múltiples
```cpp
// ❌ Múltiples asignaciones (ineficiente)
Zombie* z1 = new Zombie("name");
Zombie* z2 = new Zombie("name");
Zombie* z3 = new Zombie("name");
// ... delete z1; delete z2; delete z3;

// ✅ Una sola asignación (eficiente)
Zombie* horde = new Zombie[3];
// ... setName() para cada uno
// ... delete[] horde;
```

#### Ventajas de Una Sola Asignación
1. **Más eficiente** - Una llamada al sistema operativo
2. **Memoria contigua** - Mejor rendimiento de caché
3. **Más fácil de gestionar** - Un solo `delete[]`
4. **Menos fragmentación** de memoria

### Flujo de Ejecución Típico
```
1. new Zombie[5] se ejecuta
   ↓
2. C++ llama constructor por defecto 5 veces:
   "Zombie sin nombre creado" x5
   ↓
3. zombieHorde() asigna nombres:
   horde[0].setName("Jorge") → nombre cambia de "" a "Jorge"
   horde[1].setName("Jorge") → nombre cambia de "" a "Jorge"
   (etc.)
   ↓
4. Uso del array:
   "Jorge: BraiiiiiiinnnzzzZ..." x5
   ↓
5. delete[] horde ejecuta destructores:
   "Zombie Jorge destruido" x5
```

### Cuándo Usar Arrays de Objetos
- **Cuando necesitas múltiples objetos idénticos**
- **Cuando el número se conoce en runtime**
- **Cuando quieres eficiencia de memoria**
- **Para estructuras de datos homogéneas**

### Resumen del Ejercicio 01
El ejercicio demuestra cómo **gestionar múltiples objetos de forma eficiente** usando:
- **Una sola asignación** para todo el array
- **Constructor por defecto** + **setName()** para inicialización
- **delete[]** para liberación correcta
- **Memoria contigua** para mejor rendimiento

**Lección clave:** Arrays de objetos requieren un enfoque diferente a objetos individuales, pero ofrecen ventajas significativas en eficiencia y gestión de memoria.

---

## Ejercicio 02: "HI THIS IS BRAIN" - Punteros vs Referencias

### Objetivo
Desmitificar las **referencias** demostrando que son otra sintaxis para manipular direcciones de memoria, pero más segura que los punteros.

### El Programa Básico
```cpp
std::string brain = "HI THIS IS BRAIN";
std::string* stringPTR = &brain;       // Puntero
std::string& stringREF = brain;        // Referencia
```

### 🧉 Analogía del Mate (Argentina)

| Concepto | Analogía | Explicación |
|----------|----------|-------------|
| **Variable** | El mate original | El objeto real en memoria |
| **Puntero** | La bombilla | Necesitás usarla para acceder al mate |
| **Referencia** | "El matecito" | Otro nombre para el mismo mate |

### Resultados del Programa

#### Direcciones de Memoria (todas iguales):
```
Dirección de brain:     0x7ff7b4a76550
Dirección en stringPTR: 0x7ff7b4a76550  ← Misma dirección
Dirección de stringREF: 0x7ff7b4a76550  ← Misma dirección
```

#### Valores (todos iguales):
```
Valor de brain:        HI THIS IS BRAIN
Valor de *stringPTR:   HI THIS IS BRAIN  ← Acceso con *
Valor de stringREF:    HI THIS IS BRAIN  ← Acceso directo
```

### Diferencias Fundamentales

#### 🔵 Punteros
```cpp
std::string* ptr = &variable;    // Debe usar &
std::string* nullPtr = nullptr;  // ✅ Puede ser nullptr
ptr = &otra_variable;            // ✅ Se puede reasignar
if (ptr != nullptr) {            // ⚠️ Siempre verificar
    *ptr = "nuevo valor";        // ⚠️ Usar * para acceder
}
```

#### 🟢 Referencias
```cpp
std::string& ref = variable;     // SIN &, inicialización directa
// std::string& nullRef = nullptr;  // ❌ ERROR: no puede ser nullptr
// std::string& ref2;               // ❌ ERROR: debe inicializarse
// ref = otra_variable;             // ❌ NO reasigna, cambia el valor
ref = "nuevo valor";             // ✅ Acceso directo, sin *
```

### Tabla Comparativa Completa

| Característica | Puntero | Referencia |
|----------------|---------|------------|
| **Puede ser nullptr** | ✅ Sí | ❌ No |
| **Debe inicializarse** | ❌ No obligatorio | ✅ Sí, siempre |
| **Se puede reasignar** | ✅ Sí | ❌ No |
| **Verificación nula** | `if (ptr != nullptr)` | No necesaria |
| **Sintaxis de acceso** | `*ptr` | `ref` |
| **Declaración** | `Type* ptr = &var` | `Type& ref = var` |
| **Memoria extra** | Sí (almacena dirección) | No (alias) |

### ¿Cuándo Usar Cada Uno?

#### 🟢 USA REFERENCIAS cuando:
1. **Parámetros de función** (90% de los casos)
   ```cpp
   void procesar(const std::string& texto);  // ✅ Mejor
   void procesar(std::string* texto);        // ❌ Más complicado
   ```

2. **Evitar copias innecesarias**
   ```cpp
   void imprimir(const std::vector<int>& vec);  // No copia el vector
   ```

3. **Alias para variables complejas**
   ```cpp
   auto& elemento = contenedor[indice];  // Fácil acceso
   ```

4. **Retornar elementos modificables**
   ```cpp
   std::string& getElement(std::vector<std::string>& vec, int i) {
       return vec[i];  // Permite modificar el elemento
   }
   ```

#### 🔵 USA PUNTEROS cuando:
1. **Puede ser opcional (nullptr)**
   ```cpp
   void procesar(Config* config = nullptr);  // Parámetro opcional
   ```

2. **Memoria dinámica**
   ```cpp
   std::string* heap = new std::string("dinámico");
   delete heap;
   ```

3. **Cambiar a qué apunta**
   ```cpp
   Node* current = head;
   current = current->next;  // Navegar en lista
   ```

4. **Estructuras de datos**
   ```cpp
   struct Node {
       int data;
       Node* next;  // Puede ser nullptr (fin de lista)
   };
   ```

### Reglas de Oro

#### 🥇 Regla Principal
**PREFERÍ REFERENCIAS** cuando sea posible (90% de los casos)

#### 🥈 Excepciones para Punteros
- `nullptr` o `NULL`
- reasignación  
- Memoria dinámica
- Estructuras de datos complejas

#### 🧉 Regla del Mate
- **Referencia = "pasame el mate"** (directo, simple, siempre hay mate)
- **Puntero = "¿tenés mate?"** (puede que no haya, más verificaciones)

### Conceptos Avanzados

#### Memoria Dinámica con Referencias
```cpp
std::string* heap = new std::string("HEAP BRAIN");
std::string& ref = *heap;  // Referencia al objeto en heap

// Ambos acceden igual
std::cout << *heap << std::endl;  // HEAP BRAIN
std::cout << ref << std::endl;    // HEAP BRAIN

delete heap; 
```

#### Verificación de Seguridad
```cpp
// Con puntero (más código, pero más seguro)
if (ptr != nullptr) {
    *ptr = "nuevo valor";
}

// Con referencia (menos código, asumimos que es válido)
ref = "nuevo valor";  // Directo, sin verificaciones
```

### Resumen del Ejercicio 02
- **Referencias son "azúcar sintáctico"** para punteros
- **Misma dirección de memoria**, diferente sintaxis
- **Referencias más seguras** (no nullptr, no reasignación)
- **Punteros más flexibles** (nullptr, reasignación, memoria dinámica)
- **Usar referencias por defecto**, punteros solo cuando sea necesario

Las referencias hacen el código más limpio y seguro, pero los punteros siguen siendo necesarios para casos específicos.

### Caso Especial: Memoria Dinámica y Direcciones Diferentes

#### El Código Clave
```cpp
std::string* heapString = new std::string("HEAP BRAIN");  // 1
std::string& heapREF = *heapString;                       // 2

std::cout << "Direccion de memoria REF:" << &heapREF << std::endl;     // 3
std::cout << "Direccion de memoria PTR:" << &heapString << std::endl;  // 4
```

#### Resultado
```
Direccion de memoria REF: 0x7fad5f004080
Direccion de memoria PTR: 0x7ff7b0aef500
```

#### ¿Por qué Direcciones DIFERENTES?

**Porque son DOS objetos diferentes en lugares diferentes:**

```
STACK (memoria automática):
┌─────────────────────────┐
│ heapString (puntero)    │ ← Dirección: 0x7ff7b0aef500
│ Contiene: 0x7fad5f004080│ ← Apunta al heap
└─────────────────────────┘
         │ (apunta a)
         ▼
HEAP (memoria dinámica):
┌─────────────────────────┐
│ string "HEAP BRAIN"     │ ← Dirección: 0x7fad5f004080
│                         │
└─────────────────────────┘
```

#### Desglose de `std::string& heapREF = *heapString;`

**Paso a paso:**
1. **`heapString`** = variable puntero (vive en stack)
2. **`*heapString`** = "ve a la dirección que contiene heapString y dame el objeto"
3. **`heapREF`** = referencia (alias) al objeto en el heap
4. **Resultado:** `heapREF` ES el objeto del heap, NO el puntero


#### Verificación de Conceptos

```cpp
// Estas son IGUALES (misma dirección del objeto en heap):
std::cout << heapString << std::endl;     // 0x7fad5f004080 (dirección que contiene)
std::cout << &heapREF << std::endl;       // 0x7fad5f004080 (dirección del objeto)

// Esta es DIFERENTE (dirección del puntero en stack):
std::cout << &heapString << std::endl;    // 0x7ff7b0aef500 (donde vive el puntero)
```

#### Conceptos Clave
- **`heapString`** y **`*heapString`** son cosas completamente diferentes
- **`heapString`** vive en stack, **`*heapString`** vive en heap  
- **`heapREF`** es un alias para **`*heapString`** (mismo objeto, misma dirección)
- **Dos direcciones diferentes** porque son **objetos diferentes** en **lugares diferentes**

#### ⚠️ Peligro con Referencias y Memoria Dinámica
```cpp
std::string* heap = new std::string("TEMPORAL");
std::string& ref = *heap;  // ref apunta al objeto en heap

delete heap;               // ¡Liberamos la memoria!
// Ahora ref es una referencia "colgante" - ¡PELIGRO!
// Usar ref después del delete = comportamiento indefinido
```

**Regla:** Si usás referencias a objetos en heap, asegurate de que el objeto exista mientras uses la referencia.

---

## Ejercicio 03: "Unnecessary Violence" - Referencias vs Punteros en la Práctica

### Objetivo
Implementar dos clases similares (`HumanA` y `HumanB`) que manejan armas de forma diferente para demostrar **cuándo usar referencias vs punteros** en casos reales.

### Estructura del Proyecto
```
Weapon.hpp/cpp     → Clase base para armas
HumanA.hpp/cpp     → Humano que SIEMPRE tiene arma (referencia)
HumanB.hpp/cpp     → Humano que PUEDE tener arma (puntero)
main.cpp           → Pruebas de ambos casos
```

### Clase Weapon (Base)
```cpp
class Weapon {
private:
    std::string type;
public:
    Weapon(const std::string& weaponType);
    const std::string& getType() const;    // Método const!
    void setType(const std::string& newType);
};
```

### HumanA: Siempre Armado (Referencia)
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;    // ¡REFERENCIA! - Siempre tiene arma
public:
    HumanA(const std::string& humanName, Weapon& humanWeapon);
    void attack() const;    // Método const!
};
```

#### Características de HumanA:
- **Constructor requiere arma:** No puede existir sin arma
- **Weapon& weapon:** Referencia = arma garantizada
- **attack() const:** No modifica el estado del objeto
- **Sintaxis simple:** `weapon.getType()` (acceso directo)

#### Implementación Típica:
```cpp
// Constructor: inicialización obligatoria
HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) 
    : name(humanName), weapon(humanWeapon)  // Lista de inicialización
{
}

// Método const: no modifica el estado del objeto HumanA
// Solo lee atributos y llama a métodos const de Weapon
void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    std::cout << "*BANG!* 💥" << std::endl;
}
```

### HumanB: Opcionalmente Armado (Puntero)
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;    // ¡PUNTERO! - Puede no tener arma
public:
    HumanB(const std::string& humanName);
    void setWeapon(Weapon& newWeapon);
    void attack() const;
};
```

#### Características de HumanB:
- **Constructor sin arma:** Puede existir desarmado
- **Weapon* weapon:** Puntero = arma opcional (puede ser nullptr)
- **setWeapon():** Asigna arma después de la creación
- **Verificación de nullptr:** Obligatoria antes de usar

#### Implementación Típica:
```cpp
// Constructor: solo nombre, sin arma
HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(nullptr)
{
}

// Recibe por referencia (evita copias y garantiza objeto válido)
// Guarda como puntero (permite flexibilidad y estados opcionales)
void HumanB::setWeapon(Weapon& newWeapon)
{
    weapon = &newWeapon;  // Obtiene dirección del objeto
}

void HumanB::attack() const
{
    if (weapon != nullptr)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        std::cout << "*SLASH!* ⚔️" << std::endl;
    }
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}
```

### Comparación Práctica

| Aspecto | HumanA (Referencia) | HumanB (Puntero) |
|---------|-------------------|------------------|
| **Arma inicial** | ✅ Obligatoria en constructor | ❌ Opcional |
| **Estado sin arma** | ❌ Imposible | ✅ Posible |
| **Verificación null** | ❌ No necesaria | ✅ Obligatoria |
| **Sintaxis acceso** | `weapon.getType()` | `weapon->getType()` |
| **Flexibilidad** | 🔒 Menos flexible | 🔄 Más flexible |
| **Seguridad** | 🛡️ Más segura | ⚠️ Requiere cuidado |

### Conceptos Clave Demostrados

#### 1. **Referencias para Dependencias Obligatorias**
```cpp
HumanA bob("Bob", sword);  // Bob SIEMPRE tiene sword
// No hay forma de crear un HumanA sin arma
```

#### 2. **Punteros para Dependencias Opcionales**
```cpp
HumanB jim("Jim");         // Jim puede existir sin arma
jim.setWeapon(bow);        // Asigna arma después
// También podría no tener arma nunca
```

#### 3. **Métodos const**
```cpp
void attack() const {      // Promete no modificar el objeto
    // Solo lee name y weapon, no los modifica
    // Puede llamar a weapon.getType() porque es const
}
```

#### 4. **¿Por qué setWeapon recibe referencia pero guarda puntero?**
```cpp
void setWeapon(Weapon& newWeapon) {  // Referencia: evita copias, garantiza validez
    weapon = &newWeapon;             // Puntero: permite cambio posterior
}
```

**Razones:**
- **Referencia como parámetro:** Evita copias innecesarias, sintaxis más limpia
- **Puntero como atributo:** Permite cambiar el arma, manejar estado "sin arma"

### Señales de que weapon es un Puntero

#### En el código .cpp:
1. **Constructor:** `weapon(nullptr)` - Solo punteros pueden ser null
2. **setWeapon:** `weapon = &newWeapon;` - Asigna dirección (solo a punteros)
3. **attack:** `weapon != nullptr` - Solo se compara punteros con null
4. **attack:** `weapon->getType()` - Operador `->` es solo para punteros

#### En el archivo .hpp:
```cpp
Weapon* weapon;  // El asterisco declara que es puntero
```

### Flujo de Ejecución Típico

#### Caso HumanA (Referencia):
```cpp
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);           // Bob vinculado a club
    bob.attack();                      // "Bob attacks with their crude spiked club *BANG!* 💥"
    club.setType("enhanced club");     // Cambia el arma
    bob.attack();                      // "Bob attacks with their enhanced club *BANG!* 💥"
}  // club y bob se destruyen automáticamente
```

#### Caso HumanB (Puntero):
```cpp
{
    Weapon sword = Weapon("legendary katana");
    HumanB brendi("Brendi");           // Brendi sin arma
    brendi.attack();                   // "Brendi has no weapon to attack with!"
    brendi.setWeapon(sword);           // Asigna arma
    brendi.attack();                   // "Brendi attacks with their legendary katana *SLASH!* ⚔️"
    sword.setType("flaming sword");    // Cambia el arma
    brendi.attack();                   // "Brendi attacks with their flaming sword *SLASH!* ⚔️"
}  // sword y brendi se destruyen automáticamente
```

### Lecciones del Ejercicio 03

#### 🎯 **Cuándo usar Referencias:**
- Dependencias **obligatorias** e **inmutables**
- Cuando el objeto **siempre debe existir**
- Para **parámetros de función** (evitar copias)
- Cuando **no necesitás nullptr**

#### 🎯 **Cuándo usar Punteros:**
- Dependencias **opcionales**
- Cuando el objeto **puede cambiar** o **no existir**
- Para **estados variables** (con/sin objeto)
- Cuando **necesitás flexibilidad**

#### 🎯 **Diseño de Clases:**
- **HumanA:** Modelo para objetos con **dependencias fijas**
- **HumanB:** Modelo para objetos con **dependencias flexibles**
- Elegir según los **requisitos del problema**

### Resumen 

El **Ejercicio 03** demuestra en la práctica la diferencia entre **referencias** y **punteros** aplicado a un problema de diseño real:

- **Referencias = Garantía** (HumanA siempre armado)
- **Punteros = Flexibilidad** (HumanB opcionalmente armado)
- **Métodos const = Promesa de no modificación**
- **Diseño coherente** según los requisitos del problema

**Moraleja:** La elección entre referencia y puntero debe basarse en si la dependencia es **obligatoria** (referencia) u **opcional** (puntero).

---

## Ejercicio 06: "Harl Filter" - Switch Statement y Fall-through

### Objetivo
Implementar un sistema de filtrado de logs usando **switch statement** con **fall-through** para mostrar mensajes desde un nivel específico hacia niveles más severos.

### ¿Qué es un Switch Statement?

El `switch` es una estructura de control que evalúa una expresión y ejecuta código basado en el valor. Es como un `if-else if` múltiple pero más eficiente para comparar con valores constantes.

#### Sintaxis Básica:
```cpp
switch (variable) {
    case valor1:
        // código a ejecutar si variable == valor1
        break;
    case valor2:
        // código a ejecutar si variable == valor2
        break;
    default:
        // código si no coincide con ningún case
        break;
}
```

### 🔥 Concepto Clave: Fall-through

**Fall-through** es cuando **NO** pones `break` y el programa continúa ejecutando los siguientes `case`:

```cpp
int numero = 2;
switch (numero) {
    case 1:
        std::cout << "Uno" << std::endl;
        // SIN break - continúa al siguiente case
    case 2:
        std::cout << "Dos" << std::endl;
        // SIN break - continúa al siguiente case  
    case 3:
        std::cout << "Tres" << std::endl;
        break; // AQUÍ se detiene
    default:
        std::cout << "Otro número" << std::endl;
}
```

**Resultado si numero = 2:**
```
Dos
Tres
```

**Resultado si numero = 1:**
```
Uno
Dos
Tres
```

### 🎯 Aplicación en Harl Filter

En nuestro filtro de logs, queremos mostrar **todos los niveles desde el seleccionado hacia los más severos**:

```cpp
void Harl::filter(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelIndex = -1;
    int i = 0;
    
    // Encontrar el índice del nivel usando while
    while (i < 4)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
        i++;
    }
    
    // Switch con fall-through: DEBUG→INFO→WARNING→ERROR
    switch (levelIndex)
    {
        case 0: // DEBUG
            debug();
            // fall through - NO hay break!
        case 1: // INFO
            info();
            // fall through - NO hay break!
        case 2: // WARNING
            warning();
            // fall through - NO hay break!
        case 3: // ERROR
            error();
            break; // AQUÍ se detiene
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
```

### 📊 Jerarquía de Logs (Menos severo → Más severo)

```
DEBUG ──→ INFO ──→ WARNING ──→ ERROR
  0        1         2          3
```

### 🚀 Ejemplos de Ejecución

#### Ejemplo 1: `./harlFilter "WARNING"`
```
levelIndex = 2  →  Entra en case 2:
┌──────────────────────────────────────┐
│ case 2: warning();  ← EJECUTA        │
│ case 3: error();    ← EJECUTA (fall) │
│ break;              ← SE DETIENE     │
└──────────────────────────────────────┘

Salida:
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

#### Ejemplo 2: `./harlFilter "DEBUG"`
```
levelIndex = 0  →  Entra en case 0:
┌──────────────────────────────────────┐
│ case 0: debug();    ← EJECUTA        │
│ case 1: info();     ← EJECUTA (fall) │
│ case 2: warning();  ← EJECUTA (fall) │
│ case 3: error();    ← EJECUTA (fall) │
│ break;              ← SE DETIENE     │
└──────────────────────────────────────┘

Salida: (Los 4 niveles)
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.
I really do!

[ INFO ]
I cannot believe adding extra bacon costs more money.
You didn't put enough bacon in my burger!
If you did, I wouldn't be asking for more!

[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.

[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

#### Ejemplo 3: `./harlFilter "INVALID"`
```
levelIndex = -1  →  No coincide con ningún case:
┌──────────────────────────────────────┐
│ default:                             │
│ std::cout << "[ Probably complaining │
│              about insignificant     │
│              problems ]";            │
└──────────────────────────────────────┘

Salida:
[ Probably complaining about insignificant problems ]
```


Hay **4 termos de agua** ordenados por temperatura:

```
Termo 1: Agua tibia (DEBUG)     🌡️ 50°C
Termo 2: Agua caliente (INFO)   🌡️ 70°C  
Termo 3: Agua muy caliente (WARNING) 🌡️ 85°C
Termo 4: Agua hirviendo (ERROR) 🌡️ 100°C
```

**Switch con fall-through = "Desde este termo para arriba"**

- Si pedís **"Termo 3"** → Te damos **Termo 3 + Termo 4**
- Si pedís **"Termo 1"** → Te damos **todos los termos** (1, 2, 3, 4)
- Si pedís **"Termo inexistente"** → Te decimos **"No tenemos mate para vos"**

### ⚡ ¿Por qué Fall-through es Genial Aquí?

Sin fall-through (más código):
```cpp
if (level == "DEBUG") {
    debug(); info(); warning(); error();
} else if (level == "INFO") {
    info(); warning(); error();
} else if (level == "WARNING") {
    warning(); error();
} else if (level == "ERROR") {
    error();
} else {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
```

Con fall-through (menos código, más elegante):
```cpp
switch (levelIndex) {
    case 0: debug();    // fall through
    case 1: info();     // fall through  
    case 2: warning();  // fall through
    case 3: error(); break;
    default: std::cout << "[ Probably complaining... ]"; break;
}
```

### 🎯 Ventajas del Switch con Fall-through

1. **Menos código:** No repetir llamadas a métodos
2. **Más legible:** Secuencia clara de ejecución
3. **Más eficiente:** Una sola evaluación
4. **Escalable:** Fácil agregar nuevos niveles

### ⚠️ Peligros del Fall-through

```cpp
// ❌ PELIGRO: Fall-through accidental
switch (day) {
    case 1:
        std::cout << "Lunes" << std::endl;
        // ¡Olvidé el break! → Ejecuta también Martes
    case 2:
        std::cout << "Martes" << std::endl;
        break;
}
```

**Resultado inesperado si day = 1:**
```
Lunes
Martes  ← ¡No queríamos esto!
```

### 🛡️ Buenas Prácticas con Switch

#### 1. **Comentarios para Fall-through Intencional:**
```cpp
case 0: 
    debug();
    // fall through  ← Comenta que es intencional
case 1:
    info();
    break;
```

#### 2. **Siempre incluir default:**
```cpp
switch (value) {
    case 1: /* ... */ break;
    case 2: /* ... */ break;
    default:  // ← Siempre manejar casos inesperados
        std::cout << "Valor no reconocido" << std::endl;
        break;
}
```

#### 3. **Un case por línea (legibilidad):**
```cpp
// ✅ Legible
switch (level) {
    case 0: debug(); break;
    case 1: info(); break;
}

// ❌ Menos legible  
switch (level) { case 0: debug(); case 1: info(); break; }
```

### 🏆 Switch vs If-else: ¿Cuándo usar cada uno?

#### ✅ **USA SWITCH cuando:**
- Comparás una variable con **múltiples valores constantes**
- Los valores son **enteros, chars, o enums**
- Necesitás **fall-through**
- Tenés **muchos casos** (3 o más)

#### ✅ **USA IF-ELSE cuando:**
- Comparás con **rangos** (`if (x > 10 && x < 20)`)
- Usás **strings** complejos
- Tenés **condiciones complejas** (`if (a > b && c != d)`)
- Solo tenés **pocos casos** (1-2)

### 🎮 Ejemplo Interactivo: Menu con Switch

```cpp
void showMenu() {
    int choice;
    std::cout << "1. Jugar\n2. Opciones\n3. Salir\n";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            std::cout << "Iniciando juego..." << std::endl;
            startGame();
            break;
        case 2:
            std::cout << "Configurando opciones..." << std::endl;
            showOptions();
            break;
        case 3:
            std::cout << "¡Hasta luego!" << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Opción inválida. Intentá de nuevo." << std::endl;
            showMenu();  // Recursión para volver a mostrar
            break;
    }
}
```

### 💡 Concepto Avanzado: Switch con Enum

```cpp
enum LogLevel { DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3 };

void filterLogs(LogLevel level) {
    switch (level) {
        case DEBUG:   debug();   // fall through
        case INFO:    info();    // fall through
        case WARNING: warning(); // fall through
        case ERROR:   error();   break;
    }
}

// Uso: filterLogs(WARNING);
```

### 🚀 Resumen del Ejercicio 06

#### **Conceptos Aprendidos:**
1. **Switch statement:** Alternativa eficiente a if-else múltiple
2. **Fall-through:** Ejecución continua sin break
3. **Casos prácticos:** Filtrado de logs por severidad
4. **Buenas prácticas:** Comentarios, default, legibilidad

#### **Cuándo Usar Switch:**
- **Múltiples valores constantes** para comparar
- **Necesitás fall-through** (como nuestro filtro)
- **Mejor rendimiento** que if-else múltiple
- **Código más limpio** para casos específicos

#### **Fall-through en la Vida Real:**
- **Sistemas de permisos:** Usuario Admin → puede todo lo que puede Usuario Normal
- **Configuraciones de calidad:** Ultra → incluye todo lo de Alto + Medio + Bajo
- **Filtros progresivos:** Como nuestro Harl filter

**Lección clave:** El `switch` con fall-through es perfecto cuando querés **"desde este nivel hacia arriba/abajo"** de forma elegante y eficiente.

---
