# Módulo 02: Fixed Point y Forma Canónica

## Ejercicio 00: Mi primera clase en Forma Canónica Ortodoxa

### ¿Qué es la Forma Canónica Ortodoxa?

La Forma Canónica Ortodoxa (Orthodox Canonical Form) es un estándar de diseño de clases en C++ que asegura que tu clase se comporte correctamente cuando se copian objetos y se manejan recursos.

#### La "Regla de 3" (C++98)

Una clase en forma canónica ortodoxa debe implementar estos **tres** componentes:

1. **Constructor de copia**
2. **Operador de asignación** (operator=)
3. **Destructor**

Y aunque no forma parte de la "regla de 3" original, también se incluye:
4. **Constructor por defecto** (sin argumentos)

#### ¿Por qué es importante?

Si tu clase maneja recursos (memoria dinámica, archivos, conexiones), necesitas estos métodos para evitar:
- Pérdidas de memoria (memory leaks)
- Double-free (liberar memoria dos veces)
- Shallow copy (copias superficiales donde dos objetos apuntan al mismo recurso)

### Implementación en la clase Fixed

#### 1. Constructor por defecto
```cpp
Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
```
- Inicializa `_value` a 0
- Sin parámetros

#### 2. Constructor de copia
```cpp
Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}
```
- Toma una referencia constante a otro objeto Fixed
- Copia el valor de `other._value` a este objeto
- Se llama automáticamente cuando: `Fixed b(a);` o `Fixed b = a;` (¡ojo! esto último no es operador de asignación)

#### 3. Operador de asignación
```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // Protección contra auto-asignación
        this->_value = other._value;
    }
    return *this;  // Permite encadenar asignaciones: a = b = c;
}
```
- Se llama cuando asignas un objeto existente: `a = b;` (cuando `a` ya existe)
- Devuelve `*this` para permitir encadenamientos: `a = b = c;`
- Incluye protección contra auto-asignación: `a = a;`

#### 4. Destructor
```cpp
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
```
- Se llama automáticamente cuando el objeto sale de ámbito
- Libera recursos (en este caso no hace nada especial, pero imprime un mensaje)

### Consideraciones importantes

1. **Auto-asignación**: Siempre protege contra `a = a;` con:
   ```cpp
   if (this != &other) { ... }
   ```

2. **Devolución de referencia**: El operador de asignación debe devolver una referencia para permitir encadenamientos:
   ```cpp
   Fixed& operator=(const Fixed& other);  // No: Fixed operator=(...
   ```

3. **Parámetro por referencia constante**: Tanto el constructor de copia como el operador de asignación deben recibir una referencia constante:
   ```cpp
   Fixed(const Fixed& other);  // No: Fixed(Fixed other);
   ```

4. **Recursos dinámicos**: Si tu clase tiene punteros a memoria dinámica, debes implementar "deep copy" (copia profunda):
   ```cpp
   // Si tuvieras un puntero:
   this->ptr = new TipoDeRecurso(*other.ptr);  // Copia el contenido, no el puntero
   ```

### La Regla de 5 (C++11 en adelante)

En C++ moderno, existe la "regla de 5" que añade:
- Constructor de movimiento
- Operador de asignación de movimiento

Pero en C++98, la regla de 3 es suficiente.

### Constructor de copia vs. Sobrecarga de constructores

Una duda común: **El constructor de copia NO es una sobrecarga del constructor común** en el sentido tradicional.

#### Constructor de copia
```cpp
Fixed(const Fixed& other);  // Constructor de copia
```

#### Constructor sobrecargado (ejemplo)
```cpp
Fixed();           // Constructor por defecto
Fixed(int value);  // Constructor sobrecargado con parámetro int
```

#### La diferencia clave

- **Constructores sobrecargados**: Tienen **diferentes parámetros** entre sí (ninguno, `int`, `float`, etc.)
  * Permiten crear objetos de diferentes maneras
  * Ejemplo: `Fixed a;`, `Fixed b(42);`, `Fixed c(3.14f);`

- **Constructor de copia**: Tiene un parámetro muy específico: **una referencia constante al mismo tipo de objeto**
  * Su propósito es crear un nuevo objeto como copia de uno existente
  * Ejemplo: `Fixed b(a);` o `Fixed b = a;` (inicialización por copia)

#### ¿Por qué es especial el constructor de copia?

1. Tiene una **firma específica** que el compilador reconoce
2. El compilador lo **llama automáticamente** en ciertas situaciones:
   - Cuando inicializas un objeto con otro: `Fixed b = a;`
   - Cuando pasas un objeto por valor: `void func(Fixed obj) { ... }`
   - Cuando retornas un objeto por valor: `Fixed func() { return myFixed; }`

3. Si no lo defines, el compilador **genera uno por defecto** que hace copia miembro a miembro (shallow copy)

### Casos donde se llama a cada constructor/operador

```cpp
// Constructor por defecto
Fixed a;

// Constructor de copia
Fixed b(a);    // Forma explícita
Fixed c = a;   // Forma de inicialización (¡NO es operador de asignación!)

// Constructor sobrecargado (en ejercicios posteriores)
Fixed d(42);   // Llama a Fixed(int)
Fixed e(3.14f); // Llama a Fixed(float)

// Operador de asignación
Fixed f;      // Constructor por defecto
f = a;        // Operador de asignación
```

### Pruebas en el main.cpp

En el main.cpp del ejercicio, puedes ver cómo se usan los diferentes constructores y el operador de asignación:

```cpp
int main(void) {
    Fixed a;          // Constructor por defecto
    Fixed b(a);       // Constructor de copia
    Fixed c;          // Constructor por defecto
    
    c = b;            // Operador de asignación
    
    // Getters para mostrar valores
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}
```

## Fixed Point: Conceptos Básicos

En próximos ejercicios expandiremos la clase Fixed para trabajar con números de punto fijo, que son una forma de representar números con parte decimal usando enteros con un número fijo de bits decimales.

### ¿Qué es un número de punto fijo?

Un número de punto fijo es una representación de números con decimales usando solo enteros. A diferencia de los números de punto flotante (float, double), el punto decimal está en una posición **fija**.

En nuestra implementación:
- Usamos un `int` para almacenar el valor
- Reservamos 8 bits para la parte fraccionaria
- El resto de bits (24 en un int típico) para la parte entera

### ¿Por qué usar punto fijo?

1. **Precisión exacta** - Sin errores de redondeo como los flotantes
2. **Rendimiento predecible** - Más rápido en hardware sin unidad de punto flotante
3. **Control sobre la precisión** - Tú decides cuántos bits usar para cada parte

### Casos de uso reales:
- Gráficos por computadora
- Sistemas financieros
- Audio digital
- Sistemas embebidos

### ¿Qué significa "raw"?

"Raw" se refiere al valor bruto (en crudo) del número de punto fijo, es decir, el valor entero que realmente almacenamos internamente antes de interpretarlo como decimal.

#### Ejemplo:
Para representar `5.5` con 8 bits fraccionarios:

```
5.5 * 2^8 = 5.5 * 256 = 1408 (valor raw)
```

En binario:
```
1408 = 101 1000 0000
```

Si ponemos el punto conceptual después de 8 bits desde la derecha:
```
101.10000000
```

- Parte entera: 101 = 4 + 0 + 1 = 5
- Parte fraccionaria: 10000000 = 128/256 = 0.5

### Operaciones con getRawBits() y setRawBits()

- `getRawBits()`: Devuelve el valor entero interno (`_value`) sin conversión
- `setRawBits(raw)`: Establece directamente el valor entero interno

```cpp
Fixed a;
a.setRawBits(1408);  // Establecer a 5.5 en punto fijo
std::cout << a.getRawBits(); // Imprime 1408
```

### Conversión entre tipos (en próximos ejercicios)

De float a Fixed:
```cpp
// Para 5.5
int rawValue = roundf(5.5 * (1 << 8)); // 1408
```

De Fixed a float:
```cpp
// Si rawValue es 1408
float floatValue = 1408.0f / (1 << 8); // 5.5
```

### Cálculos usando la calculadora bc

Para hacer cálculos de punto fijo en la terminal:

```bash
# Iniciar bc con soporte matemático
bc -l

# Convertir de decimal a punto fijo (8 bits)
5.5 * 2^8  # Resultado: 1408

# Convertir de punto fijo a decimal
1408 / 2^8  # Resultado: 5.5

# Trabajar en binario
obase=2
5.5 * 2^8  # Resultado en binario: 10110000000
obase=10

# Suma/resta (directa con valores raw)
1408 + 256  # 5.5 + 1.0 = 1664 (6.5)

# Multiplicación en punto fijo
(1408 * 768) / 2^8  # (5.5 * 3.0) = 16.5
```




