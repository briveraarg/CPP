# Notas del Module 05

## ¿Qué son y cuál es su objetivo en C++ las excepciones?

Las excepciones son el mecanismo de C++ moderno para reportar y manejar condiciones de error o situaciones anómalas que ocurren durante la ejecución del programa.

Su objetivo principal es ofrecer una forma formal y bien definida para que la parte del código que detecta un error pueda comunicarlo a otra parte del programa encargada de manejarlo.

En el contexto de la filosofía de C++ y la Programación Orientada a Objetos

1. **Seguridad y robustez**
   Las excepciones obligan al código a reconocer y manejar condiciones de error. A diferencia de los códigos de error tradicionales (como devolver enteros), las excepciones no manejadas detienen el programa, evitando continuar con datos corruptos o resultados inválidos.

2. **Desenredo de la pila (Stack Unwinding)**
   Cuando se lanza una excepción, el flujo salta a un bloque `catch`. Durante este proceso, C++ invoca automáticamente los destructores de los objetos locales creados previamente. Esto es clave para el principio **RAII**, asegurando la liberación correcta de memoria dinámica, archivos, sockets, etc.

3. **Separación de responsabilidades**
   Permiten una separación clara entre:

   * El código que detecta el error (`throw`).
   * El código que lo maneja (`catch`).


## Las tres palabras clave del manejo de excepciones

El mecanismo se basa en tres palabras reservadas:

### `try`

Delimita un bloque donde puede ocurrir una excepción. Si algo falla dentro, el flujo salta al bloque `catch` correspondiente.

### `throw`

Lanza una excepción. Generalmente se crea un objeto temporal que representa el error detectado.

### `catch`

Captura una excepción lanzada desde un bloque `try`. El manejador puede registrar el error, solucionarlo o limpiar recursos.


### Ejemplo de excepción personalizada

#### `.hpp`

```cpp
class GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw();
};
```

#### `.cpp`

```cpp
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 <= MAX_GRADE)
        throw GradeTooHighException();
    --_grade;
}
```

### Explicación

1. **`class GradeTooHighException : public std::exception`**
   Se define una nueva excepción que hereda de `std::exception`. Esto permite capturarla usando `catch(std::exception&)`.

2. **Miembros públicos**
   `what()` es accesible desde fuera de la clase.

3. **`virtual const char* what() const throw()`**

   * Devuelve una cadena descriptiva del error.
   * `virtual`: permite polimorfismo.
   * `const`: no modifica el estado del objeto.
   * `throw()`: especificación de C++98 indicando que no lanza excepciones.

### Comentario visto en la implementación de excepciones

```cpp
/*
 * Implementación de what() para las excepciones anidadas.
 * Se devuelve una cadena literal con duración estática.
 */
```

### Desglose del comentario

1. **Implementación de what()**
   La función devuelve una descripción del tipo de error.

2. **Excepciones anidadas**
   Describe un entorno donde una excepción podría conservar información sobre otra mediante `std::nested_exception`.

3. **Duración estática**
   Las cadenas literales tienen duración estática: existen durante toda la ejecución del programa.

4. **Importancia del comentario**
   Señala que `what()` devuelve un puntero a una cadena literal válida durante toda la ejecución.


### Cálculo del tamaño de un array

```cpp
const int tableSize = sizeof(table) / sizeof(table[0]);
```

Calcula la cantidad de elementos del array `table` durante la compilación.
Ejemplo:

* Si `Entry` ocupa 16 bytes y `table` tiene 10 elementos:

  * `sizeof(table) = 160`
  * `sizeof(table[0]) = 16`
  * `160 / 16 = 10`

---

### Por qué `Intern::makeForm` devuelve un puntero `AForm*` y no una referencia `AForm&`

### 1. Diferencias fundamentales

### Devolver un puntero (`AForm*`)

* Permite devolver `NULL` si no existe el tipo solicitado.
* Permite crear objetos en memoria dinámica con `new`.
* El llamador puede liberar el formulario con `delete`.
* Es el patrón estándar al implementar una "factory".

### Devolver una referencia (`AForm&`)

* No puede representar una referencia nula.
* No puede referirse a un objeto local (en stack).
* No es adecuada para objetos creados con `new` cuya propiedad debe transferirse.

### 2. Por qué Intern no puede devolver una referencia

El Intern crea nuevos formularios mediante:

```cpp
return new RobotomyRequestForm(target);
```

Si intentara devolver una referencia, bloquearía la posibilidad de que el usuario destruya el objeto, generando fugas de memoria.

### 3. Razón de diseño del subject

El Intern actúa como una factory:

```
Intern -> produce formularios -> los devuelve
```

Las factories en C++ devuelven punteros porque:

* permiten objetos dinámicos
* permiten devolver `NULL`
* el llamador controla el lifetime
* encajan con el patrón

### 4. Si el formulario no existe

El Intern debe poder hacer:

```cpp
return NULL;
```

Esto solo es posible con punteros.

### 5. Comparación breve

| Característica      | Puntero (`AForm*`) | Referencia (`AForm&`) |
| ------------------- | ------------------ | --------------------- |
| Puede devolver NULL | Sí                 | No                    |
| Objetos dinámicos   | Sí                 | No apropiado          |
| Control del usuario | Sí (`delete`)      | No                    |
| Patrón factory      | Sí                 | No                    |

### Resumen

El Intern devuelve un puntero porque:

1. Crea formularios con `new`.
2. Puede necesitar devolver `NULL`.
3. El llamador debe controlar la vida del objeto.
4. Es la implementación estándar del patrón factory en C++98.

