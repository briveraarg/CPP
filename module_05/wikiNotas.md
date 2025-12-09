
# Notas del Module 05

### ¿Qué son y cuál es su objetivo en C++ las excepciones?

Las excepciones son el mecanismo de C++ moderno para reportar y manejar condiciones de error o anomalías que ocurren durante la ejecución del programa,.

Su objetivo principal es proporcionar una forma formal y bien definida para que la parte del código que detecta un error pueda comunicar ese problema a otra parte del programa que esté diseñada para manejarlo.

En el contexto de la filosofía de C++ y la Programación Orientada a Objetos (POO):

1.  **Seguridad y Robustez:** Las excepciones obligan al código que realiza una llamada a reconocer y manejar una condición de error. A diferencia de los códigos de error antiguos (como devolver un `int`), las excepciones no manejadas detienen la ejecución, evitando que el programa continúe con datos incorrectos o resultados erróneos,,.
2.  **Desenredo de la Pila (Stack Unwinding):** Cuando se lanza una excepción, el programa salta a un manejador (`catch`). Durante este proceso, C++ garantiza que los destructores de todos los objetos locales que fueron construidos se invocan automáticamente,,. Esto es esencial para el principio **RAII (Resource Acquisition Is Initialization)**, ya que asegura que recursos como la memoria dinámica (`delete`), *sockets* o archivos se liberen, incluso ante fallos,,,.
3.  **Separación de Preocupaciones:** Permiten una separación limpia entre el código que detecta el error (`throw`) y el código que lo resuelve (`catch`),,.

### Las Tres Palabras Clave

El mecanismo de manejo de excepciones se basa en tres palabras reservadas fundamentales:

1.  **`try`**: Delimita un bloque de código. Aquí se coloca el código que se va a "intentar" ejecutar y donde se monitorean las anomalías,. Si ocurre una excepción dentro de este bloque, el control salta inmediatamente a un manejador `catch`,.
2.  **`throw`**: Es la instrucción que lanza o dispara una excepción cuando se detecta una situación anormal,,. Cuando se ejecuta `throw`, se crea un objeto temporal que representa la excepción,.
3.  **`catch`**: Se utiliza para "capturar" una excepción lanzada por un bloque `try`,,. El manejador `catch` procesa el error y puede intentar una acción correctiva o de limpieza.

### ejemplo

Ese bloque de código que me muestras es un ejemplo de cómo se declara una clase de excepción personalizada en C++.

hpp

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};


cpp
		void Bureaucrat::incrementGrade()
		{
			if (_grade - 1 <= MAX_GRADE)
				throw GradeTooHighException();
			--_grade;
		}
Se lee de la siguiente manera:

1.  **`class GradeTooHighException : public std::exception`**:
	*   Estás definiendo una nueva clase llamada `GradeTooHighException`.
	*   Esta clase **hereda públicamente** de `std::exception`. Esto es una práctica recomendada en C++, ya que te permite capturar cualquier excepción de tu jerarquía usando `std::exception&`.

2.  **`public:`**:
	*   Indica que los miembros que siguen son accesibles desde fuera de la clase.

3.  **`virtual const char* what() const throw();`**:
	*   Este es el **prototipo** de una función miembro clave.
	*   `virtual`: Indica que esta función puede ser redefinida (sobrescrita) en clases derivadas. Aunque aquí no hay una clase derivada, se recomienda usar `virtual` para que las excepciones sean polimórficas (manejo en tiempo de ejecución).
	*   `const char* what()`: Es la función que devuelve un puntero a una cadena de caracteres (`const char*`). Esta cadena típicamente contiene la descripción del error.
	*   `const`: Indica que esta función no modifica el estado interno del objeto `GradeTooHighException`.
	*   `throw()`: En C++ moderno se prefiere usar `noexcept`. Esta es la especificación de excepción de C++98, que indica que la función no lanzará ninguna excepción.

**En resumen, esta clase define un nuevo tipo de error que, al ser lanzado (`throw`), puede ser capturado por un bloque `catch` para que el programa gestione el caso de una calificación demasiado alta.**


### comentario visto en las excepciones

```

/*
 * Implementación de what() para las excepciones anidadas.
 * Se devuelve una cadena literal con duración estática.
 */
```

### Desglose del comentario
1. Implementación de what() para las excepciones anidadas.
Se refiere a que el código que sigue define una función miembro llamada what().
La función what() es un método estándar definido en la clase base std::exception en C++.
Esta función está diseñada para devolver una cadena de caracteres (const char*) que describe el error que ocurrió.

2. El término "excepciones anidadas" sugiere que este manejo de errores es parte de un sistema donde una excepción puede capturarse dentro de otro bloque try-catch, y se puede conservar la información de la excepción original (usando std::nested_exception)

3. Se devuelve una cadena literal con duración estática.
Esta es la parte clave sobre "duración estática" (static duration).
En C++, una cadena literal (por ejemplo, "Este es un mensaje de error") tiene automáticamente duración estática. Esto significa que la memoria para esa cadena se asigna una sola vez al inicio del programa y persiste durante toda la ejecución del mismo.

4. El comentario es importante porque le indica al lector del código que la función what() devuelve un puntero a esta memoria persistente.



La expresión
const int tableSize = sizeof(table) / sizeof(table[0]);

lo que hace es calcular cuántos elementos hay en el array table en tiempo de compilación, dividiendo el tamaño en bytes del array completo entre el tamaño en bytes de un elemento (el primero).

Por ejemplo, si Entry ocupa 16 bytes y table tiene 10 elementos:

sizeof(table) = 10 * 16 = 160
sizeof(table[0]) = 16
160 / 16 = 10 → número de elementos

