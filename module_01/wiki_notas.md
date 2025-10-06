### Resumen Ejecutivo (Basado en el Ejercicio)

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

#### 1. Creación del Array
```cpp
Zombie* horde = new Zombie[5];  // Crea 5 zombies
```
- C++ llama automáticamente al **constructor por defecto** 5 veces
- Cada zombie se crea con `name = ""` (vacío)

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
- Necesitás `nullptr`
- Necesitás reasignación  
- Memoria dinámica
- Estructuras de datos complejas

#### 🧉 Regla del Mate
- **Referencia = "Che, pasame el mate"** (directo, simple, siempre hay mate)
- **Puntero = "Che, ¿tenés mate?"** (puede que no haya, más verificaciones)

### Conceptos Avanzados

#### Memoria Dinámica con Referencias
```cpp
std::string* heap = new std::string("HEAP BRAIN");
std::string& ref = *heap;  // Referencia al objeto en heap

// Ambos acceden igual
std::cout << *heap << std::endl;  // HEAP BRAIN
std::cout << ref << std::endl;    // HEAP BRAIN

delete heap;  // ¡CUIDADO! ref ahora es peligroso
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

**Moraleja:** Las referencias hacen el código más limpio y seguro, pero los punteros siguen siendo necesarios para casos específicos.

### Caso Especial: Memoria Dinámica y Direcciones Diferentes

#### El Código Clave
```cpp
std::string* heapString = new std::string("HEAP BRAIN");  // 1
std::string& heapREF = *heapString;                       // 2

std::cout << "Direccion de memoria REF:" << &heapREF << std::endl;     // 3
std::cout << "Direccion de memoria PTR:" << &heapString << std::endl;  // 4
```

#### Resultado Típico
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

#### Analogía del Papel con Dirección

```cpp
std::string* heapString = new std::string("HEAP BRAIN");  
// heapString = "papel con dirección: Av. Corrientes 1234"

std::string& heapREF = *heapString;
// *heapString = "ve a Corrientes 1234 y traeme el mate"
// heapREF = "ahora ese mate tiene otro nombre: 'matecito'"
```

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
