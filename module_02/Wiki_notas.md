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

1.
//fixed 256 -> se escribre 1 << _fractionalBits 4 * 256 = 100(en bits)

Exacto, exactamente eso. Vamos a desglosarlo.

---

### 1️⃣ Punto fijo vs float

#### Float (`float` en C++)

* Es un número **de punto flotante**, con **mantisa de 23 bits** (para `float`) y **exponente**.
* Puede representar **muchos más decimales** y rangos grandes, pero sigue siendo aproximado en ciertos valores.
* Ejemplo: `1234.4321f` → almacenado como algo cercano a `1234.43212890625`.

#### Punto fijo (`Fixed` con `_fractionalBits = 8`)

* `_value` es un entero que representa:

[
\text{valor real} = \frac{\text{_value}}{2^{_fractionalBits}}
]

* Con `_fractionalBits = 8` → pasos de `1/256 ≈ 0.00390625`.
* Entonces **solo puedes representar números con incrementos de 0.00390625**.

---

### 2️⃣ Precisión y exactitud

* `float` tiene **aproximadamente 7 decimales significativos**.
* Tu `Fixed` con 8 bits fraccionarios tiene:

```
1/256 ≈ 0.00390625 → solo unos 3 decimales aproximados
```

* Ejemplo real:

```cpp
Fixed a(1234.4321f);
std::cout << a.toFloat(); // 1234.4296875
```

* La diferencia con el float original:

```
1234.4321 - 1234.4296875 ≈ 0.0024125
```

---

### 3️⃣ Conclusión

* Sí, **punto fijo es menos preciso** que un float con pocos bits fraccionarios.
* Pero **es más predecible**: cada incremento es exacto (`1 << _fractionalBits`), mientras que el float depende de la mantisa y el exponente.
* Para **controlar precisión**, podés aumentar `_fractionalBits`:

```cpp
static const int _fractionalBits = 16; // pasos de 1/65536 ≈ 0.00001526
```

→ mucho más exacto, pero `_value` sigue siendo un `int` (o necesitás `long` si se pasa de rango).

---

Si querés, puedo hacerte un **mini cuadro comparando Fixed y float** con rangos, pasos y precisión para que lo veas clarito.
¿Querés que lo haga?


¡Perfecto! Vamos paso a paso.

---

## 1️⃣ Comparación Fixed vs Float

| Característica         | Float (`float`)                                                 | Fixed (`_fractionalBits=8`)                                  |
| ---------------------- | --------------------------------------------------------------- | ------------------------------------------------------------ |
| Representación interna | Mantisa + exponente                                             | Entero, escalado por 2^bits fraccionarios                    |
| Precisión              | ~7 decimales significativos                                     | Paso = 1/256 ≈ 0.00390625                                    |
| Rango                  | Muy amplio                                                      | Limitado al tipo entero (`int`)                              |
| Exactitud              | Aproximada                                                      | Exacta para los pasos que permite                            |
| Operaciones            | Suma/resta/multi/división pueden perder precisión por redondeos | Suma/resta exacta, multiplicación/división requiere cuidado  |
| Uso típico             | Cálculos científicos, gráficos                                  | Juegos, control, DSP, cuando querés exactitud en incrementos |

---

## 2️⃣ ¿Qué significa “más predecible”?

Cuando digo que **Fixed es más predecible**:

* Cada incremento es **exacto y constante**:

```cpp
_value += 1; // siempre aumenta 1/256
```

* No dependés de los bits de mantisa ni del exponente como en float.
* Con float, sumar 0.0001 puede **no cambiar nada** si el número es muy grande, porque el float solo puede representar ciertos valores “discretos” dependiendo de la magnitud.

💡 En otras palabras:

> Con Fixed, sabés **exactamente** qué números son representables y cuáles no.
> Con Float, la representación depende de la magnitud del número y de la mantisa → el error relativo cambia según el valor.

---

Si querés, puedo hacer un **mini esquema visual** mostrando cómo un float y un Fixed representan los mismos números y cómo la “discretización” es más clara en Fixed.
¿Querés que lo haga?

