# Módulo 01: Memoria, Referencias y Switch

## Ejercicio 00: Zombie - Heap vs. Stack

### El dilema: ¿Cuánto tiempo vive mi objeto?

Este ejercicio demuestra la diferencia fundamental en la **vida útil (lifespan)** de un objeto dependiendo de dónde se cree.

### 1\. Caso `randomChump` -\> STACK (Pila)

```cpp
void randomChump(std::string name) {
    Zombie zombie(name);  // Se crea en la STACK
    zombie.announce();
    // Fin de la función: el destructor se llama AUTOMÁTICAMENTE aquí.
}
```

  * **¿Por qué STACK?** Porque el zombi es un "usar y tirar". Solo sirve dentro de esta función.
  * **Ventaja:** Gestión automática. Cero riesgo de *memory leaks*.
  * **Regla:** Si el objeto **no necesita existir** después de que termine la función, usa la Stack.

### 2\. Caso `newZombie` -\> HEAP (Montón)

```cpp
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name); // Se crea en el HEAP
    return zombie; // Devolvemos la dirección. El objeto SIGUE VIVO.
}
```

  * **¿Por qué HEAP?** Porque necesitamos que el zombi sobreviva al final de la función `newZombie` para usarlo en el `main`.
  * **Desventaja:** Gestión manual. **Tú eres el responsable** de matarlo.

### Tabla de Decisión Rápida

| Necesidad | Zona de Memoria | Responsable de `delete` | Función ejemplo |
| :--- | :--- | :--- | :--- |
| Objeto temporal / local | **STACK** | Automático (Compilador) | `randomChump` |
| Objeto persistente / dinámico | **HEAP** | **Manual (Programador)** | `newZombie` |

-----

## Ejercicio 01: "Moar brainz\!" - Arrays de Objetos

### El Reto

Crear una horda (array) de `N` zombies en el Heap de una sola vez.

### La Trampa de los Arrays y el Constructor

Cuando haces `new Zombie[5]`, C++ intenta crear 5 objetos inmediatamente. Como no puedes pasarle argumentos individuales a un array en la creación (en C++98 standard), el compilador **exige** un constructor sin parámetros.

```cpp
Zombie* horde = new Zombie[N]; // Llama N veces a Zombie()
```

### Flujo de Ejecución Correcto

1.  **Reserva e Inicialización por defecto:**
      * Se llama a `new Zombie[N]`.
      * Se ejecuta el constructor `Zombie()` (sin nombre) `N` veces.
2.  **Personalización:**
      * Iteramos sobre el array y llamamos a `setName()` para darles identidad.
3.  **Uso:**
      * Usamos la horda.
4.  **Limpieza:**
      * `delete[] horde;` (El `[]` es vital para decirle a C++ que destruya *todos* los elementos, no solo el primero).

### Diferencias Clave: Ex00 vs Ex01

| Característica | Objeto Único (`newZombie`) | Array de Objetos (`zombieHorde`) |
| :--- | :--- | :--- |
| **Asignación** | `new Zombie("Nombre")` | `new Zombie[N]` |
| **Constructor** | Parametrizado | **Por defecto** (vacío) |
| **Configuración** | En el constructor | Vía `setName()` posterior |
| **Liberación** | `delete z;` | `delete[] horde;` |

-----

## Ejercicio 02: "HI THIS IS BRAIN" - Punteros vs Referencias

### Analogía del Mate 🧉

  * **Variable:** El mate físico.
  * **Puntero:** Una hoja de papel con la dirección GPS de dónde está el mate. (Podés borrar la dirección, escribir otra, o que el papel esté en blanco `nullptr`).
  * **Referencia:** Un apodo para el mate ("El verde"). Si agarrás "El verde", estás agarrando el mate. No podés tener un apodo para "nada".

### El Caso Confuso: Direcciones "Diferentes"

Tu apunte toca un tema avanzado crucial: **Punteros a Heap vs Referencias a Heap**.

```cpp
std::string* strPtr = new std::string("Texto");
std::string& strRef = *strPtr;
```

Si imprimimos direcciones (`&`), pasa esto:

1.  `&strRef`: Te da la dirección del **OBJETO** en el Heap (0x500...).
2.  `strPtr`: Te da la dirección del **OBJETO** en el Heap (0x500...).
3.  `&strPtr`: Te da la dirección de la **VARIABLE PUNTERO** en el Stack (0x7ff...).

> **Visualización:**
>
> **STACK** (Tu mesa de trabajo)
> `[ Variable strPtr (vive aquí) ]` -\> Guarda el valor: `0x500`
>
> **HEAP** (El almacén)
> `[ Dirección 0x500 ]` -\> Aquí vive el objeto "Texto".
> `[ strRef ]` -\> Es solo un alias directo a `0x500`.

### Tabla Definitiva: Puntero vs Referencia

| Característica | Puntero (`Type*`) | Referencia (`Type&`) |
| :--- | :--- | :--- |
| **Nulidad** | Puede ser `nullptr`. | **Nunca** puede ser nula. |
| **Reasignación** | Puede cambiar a qué apunta. | **Inmutable** (siempre refiere al mismo objeto). |
| **Inicialización** | Puede quedar sin inicializar (peligroso). | Debe inicializarse al declararse. |
| **Sintaxis** | `*ptr` y `ptr->` | Transparente (como el objeto original). |
| **Uso principal** | Memoria dinámica, estructuras, opcionales. | Pasaje de parámetros, alias, retorno seguro. |

-----

## Ejercicio 03: Unnecessary Violence

Este ejercicio enseña **Diseño de Clases** basado en relaciones.

### Composición (HumanA) vs. Agregación (HumanB)

1.  **HumanA (Referencia):**

      * "Yo SOY un guerrero y MI espada es parte de mí".
      * La relación es fuerte. No puede existir `HumanA` sin `Weapon`.
      * Se usa `Weapon&` en el constructor.

2.  **HumanB (Puntero):**

      * "Yo soy una persona, y A VECES tengo un arma".
      * La relación es débil/opcional.
      * Se usa `Weapon*` porque puede ser `nullptr` (estar desarmado).

### ¿Por qué `setWeapon` recibe referencia pero guarda puntero?

En `HumanB`:

```cpp
void setWeapon(Weapon& newWeapon) {
    this->_weapon = &newWeapon;
}
```

  * **Recibe referencia:** Para asegurar que le pasas un arma válida (no null) y evitar copias.
  * **Guarda puntero:** Porque necesita la flexibilidad de poder cambiarla o apuntar a nada más tarde (aunque en este setter específico garantizamos validez).

-----

## Ejercicio 06: Harl Filter - Switch & Fall-through

### El concepto de "Fall-through" (Caída en cascada)

Normalmente, el `break` es obligatorio en un `switch`. Pero aquí usamos su ausencia como una *feature*.

La lógica de los niveles de log es jerárquica:

  * Si quiero ver **WARNING**, también quiero ver **ERROR** (porque es más grave).
  * Pero no quiero ver **INFO** ni **DEBUG** (ruido).

### La Estructura del Switch

Como C++ no permite `switch(std::string)`, primero convertimos el string a un índice `int` (0 a 3) y luego hacemos la magia:

```cpp
switch (levelIndex) {
    case 0: // DEBUG
        this->debug();
        // ¡SIN BREAK! Cae al siguiente
    case 1: // INFO
        this->info();
        // ¡SIN BREAK! Cae al siguiente
    case 2: // WARNING
        this->warning();
        // ¡SIN BREAK! Cae al siguiente
    case 3: // ERROR
        this->error();
        break; // <--- ¡AQUÍ PARAMOS!
    default:
        std::cout << "[ Quejándose de cosas insignificantes ]" << std::endl;
}
```

### La Analogía de los Termos 🧉 (Revisitada)

Imaginá que tenés una torre de filtros de agua.

1.  Filtro DEBUG (Arriba de todo)
2.  Filtro INFO
3.  Filtro WARNING
4.  Filtro ERROR (Abajo de todo)

Si echás agua en el nivel **WARNING**, el agua baja y pasa por ERROR también. Pero nunca toca los filtros de arriba (DEBUG/INFO). ¡Eso es el Fall-through\!