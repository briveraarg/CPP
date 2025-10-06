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
