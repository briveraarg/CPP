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

Si la clase maneja recursos (memoria dinámica, archivos, conexiones), necesito estos métodos para evitar:
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
   ```

3. **Parámetro por referencia constante**: Tanto el constructor de copia como el operador de asignación deben recibir una referencia constante:
4. **Recursos dinámicos**: Si tu clase tiene punteros a memoria dinámica, debes implementar "deep copy" (copia profunda):
   ```cpp
   // Si tuvieras un puntero:
   this->ptr = new TipoDeRecurso(*other.ptr);  // Copia el contenido, no el puntero
   ```

- Operador de asignación de movimiento

### Constructor de copia vs. Sobrecarga de constructores

Una duda común: **El constructor de copia NO es una sobrecarga del constructor común** en el sentido tradicional.

#### Constructor de copia
#### Constructor sobrecargado (ejemplo)
```cpp
Fixed(int value);  // Constructor sobrecargado con parámetro int
```
#### La diferencia clave

- **Constructores sobrecargados**: Tienen **diferentes parámetros** entre sí (ninguno, `int`, `float`, etc.)
  * Permiten crear objetos de diferentes maneras

- **Constructor de copia**: Tiene un parámetro muy específico: **una referencia constante al mismo tipo de objeto**
  * Ejemplo: `Fixed b(a);` o `Fixed b = a;` (inicialización por copia)

#### ¿Por qué es especial el constructor de copia?

1. Tiene una **firma específica** que el compilador reconoce
2. El compilador lo **llama automáticamente** en ciertas situaciones:
   - Cuando pasas un objeto por valor: `void func(Fixed obj) { ... }`
   - Cuando retornas un objeto por valor: `Fixed func() { return myFixed; }`
3. Si no lo defines, el compilador **genera uno por defecto** que hace copia miembro a miembro (shallow copy)

### Casos donde se llama a cada constructor/operador

```cpp

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

## Ejercicio 01: Conversión y representación más útil

### Objetivo

Mejorar la clase `Fixed` para que pueda construirse a partir de `int` y `float`, convertir entre representaciones y poder imprimir el valor en formato decimal.

### Cambios principales
- Constructor `Fixed(const int nbr)`: convierte el entero a la representación fixed multiplicando por `(1 << _fractionalBits)`.
- Constructor `Fixed(const float nbr)`: convierte el float a fixed usando `roundf(nbr * (1 << _fractionalBits))` para minimizar sesgo.
- `float toFloat(void) const`: reconstruye el `float` a partir del raw dividiendo por `(1 << _fractionalBits)`.
- `int toInt(void) const`: convierte a entero. En esta implementación se decidió usar `static_cast<int>(toFloat())` para que la semántica coincida con un cast a `int` (truncamiento hacia 0).
- Sobrecarga de `operator<<` para imprimir la representación en punto flotante (usa `toFloat()` internamente).

### Notas sobre `roundf` y truncamiento
- Se permite el uso de `roundf` (de `<cmath>`) en el enunciado. Usarlo evita el truncamiento y produce la representación fija más cercana al float original.
- Ejemplo: `42.42 * 256 = 10859.52` → `roundf` produce `10860` (toFloat ≈ 42.4219). Un cast directo a `int` produciría `10859` (toFloat ≈ 42.41797).

### Truncamiento: qué es y por qué importa

El truncamiento consiste en eliminar la parte fraccionaria de un número y quedarse solo con la parte entera. En C++ se obtiene con un cast a entero (`static_cast<int>(x)`) o con `std::trunc(x)`. El truncamiento se realiza hacia cero, es decir:

-  3.9  -> 3
- -3.9  -> -3

Diferencias con otras operaciones comunes:
- Floor (piso): `std::floor(x)` devuelve el mayor entero menor o igual que `x`.
    -  3.9 -> 3
    - -3.9 -> -4
- Ceil (techo): `std::ceil(x)` devuelve el menor entero mayor o igual que `x`.
    -  3.1 -> 4
    - -3.1 -> -3
- Round (redondeo): `std::round(x)` redondea al entero más cercano (los .5 se redondean al entero más alejado de cero por defecto en `round`).
    -  3.4 -> 3
    -  3.6 -> 4
    - -3.6 -> -4

Por qué importa en la clase `Fixed`:
- `Fixed::toInt()` en esta implementación usa `static_cast<int>(toFloat())`, por lo que devuelve la parte entera por truncamiento hacia cero. Esto es coherente con el comportamiento de `(int)someFloat`.
- En el constructor `Fixed(const float nbr)` usamos `roundf(nbr * (1 << _fractionalBits))` para convertir el float escalado al entero más cercano **antes** de almacenar el `raw`. Esto reduce el sesgo al convertir float → fixed. Si en lugar de `roundf` hubiéramos hecho un simple cast a `int`, estaríamos truncando y perdiendo precisión sistemáticamente hacia abajo (para valores positivos) o hacia arriba (para negativos).

Ejemplos prácticos:
- Conversión a fixed con `roundf`:
    - `42.42 * 256 = 10859.52` → `roundf` -> `10860` → `toFloat()` ≈ `42.421875`
- Conversión truncando (cast):
    - `42.42 * 256 = 10859.52` → `static_cast<int>` -> `10859` → `toFloat()` ≈ `42.41796875`
- Diferencia en negativos:
    - `-1.7` -> `static_cast<int>(-1.7)` = `-1` (trunc hacia 0), pero `std::floor(-1.7)` = `-2`.

Recomendaciones:
- Mantener `roundf` en el constructor desde `float` si quieres minimizar el error al convertir a punto fijo.
- Mantener `toInt()` como truncamiento si quieres que su comportamiento coincida con `(int)someFloat` (es la opción más intuitiva para casts en C++). Si preferís otra semántica (p. ej. `floor` o `round`), documentadlo claramente y/o añadid un método alternativo (por ejemplo `toIntFloor()` o `toIntRound()`).

### Firma de funciones añadidas
```cpp
Fixed(const int nbr);
Fixed(const float nbr);
float toFloat(void) const;
int toInt(void) const;
std::ostream& operator<<(std::ostream& os, const Fixed& f);
```

### Ejemplo en `main` y salida esperada
Código de ejemplo (simplificado):
```cpp
Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);
a = Fixed(1234.4321f);
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
```
Salida esperada (valores aproximados):
```
a is 1234.43
b is 10
c is 42.4219
d is 10
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

### Nota: pre-incremento vs post-incremento (operator++)

En la clase `Fixed` (y en C++ en general) existen dos formas de sobrecargar el operador de incremento: `operator++()` y `operator++(int)`.

- Pre-incremento (prefijo):
    - Firma: `Fixed& Fixed::operator++()`
    - Se usa con la sintaxis `++x`.
    - Incrementa el objeto y devuelve una **referencia** al objeto ya incrementado (evita copias).
    - Ejemplo: `Fixed b = ++a;` → `a` se incrementa y `b` toma el nuevo valor.

- Post-incremento (postfijo):
    - Firma: `Fixed Fixed::operator++(int)` (el `int` es un parámetro ficticio utilizado solo para distinguir la firma).
    - Se usa con la sintaxis `x++`.
    - Devuelve por **valor** una copia del estado anterior y luego incrementa el objeto.
    - Ejemplo: `Fixed c = a++;` → `c` recibe el valor antiguo de `a`, y `a` queda incrementado.

Notas:
- El compilador elige la versión según la sintaxis (`++x` vs `x++`).
- Prefiere la versión prefija para tipos complejos cuando no necesitas la copia antigua (más eficiente).
- Implementación típica: definir la prefija y hacer que la postfija cree una copia y delegue en la prefija (como en `Fixed.cpp`).

Ejemplo de prueba para `main.cpp`:

```cpp
Fixed a(1);
Fixed b = ++a; // a = 2, b = 2
Fixed c = a++; // c = 2 (valor antiguo), a = 3
std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
```

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



## Nota: `operator<<` — ¿por qué usamos `toFloat()` y no `toInt()`?

Al sobrecargar `operator<<` para `Fixed` normalmente queremos imprimir el valor numérico en forma decimal (con su parte fraccionaria). Por eso la implementación común es:

```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
        os << f.toFloat(); // mostramos el número con decimales
        return os;
}
```

Razones clave:
- `toFloat()` reconstruye el valor real incluyendo la fracción (p. ej. `42.4219`).
- `toInt()` devuelve la parte entera truncada (p. ej. `42`) — perderías la parte fraccionaria al imprimir.

Opciones y formatos:
- Si querés controlar la precisión visual, usa manipuladores de flujo:
    ```cpp
    #include <iomanip>
    std::cout << std::fixed << std::setprecision(2) << f << std::endl; // 2 decimales
    ```
- Si necesitas otras representaciones útiles:
    - `f.getRawBits()` para ver el valor raw entero
    - `f.toInt()` para imprimir solo la parte entera

Ejemplo rápido comparativo:

```cpp
Fixed a(42.42f);
std::cout << "toFloat: " << a.toFloat() << std::endl; // p. ej. 42.4219
std::cout << "toInt:   " << a.toInt()   << std::endl; // 42
std::cout << "operator<<: " << a << std::endl;        // usa toFloat -> 42.4219
```




