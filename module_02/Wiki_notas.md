# Módulo 02: Fixed Point y Forma Canónica Ortodoxa

## Ejercicio 00: Mi primera clase en Forma Canónica Ortodoxa

### ¿Qué es la Forma Canónica Ortodoxa (OCF)?

Es un estándar de diseño en C++ (especialmente estricto en C++98) que asegura que tu clase se comporte de manera predecible y segura al copiar objetos.

#### La "Regla de 4"

Para cumplir con la OCF, tu clase debe declarar explícitamente:

1.  **Constructor por defecto**: `Fixed(void)`
2.  **Constructor de copia**: `Fixed(const Fixed& other)`
3.  **Operador de asignación de copia**: `Fixed& operator=(const Fixed& other)`
4.  **Destructor**: `~Fixed()`

#### ¿Por qué es vital?

Si tu clase maneja recursos (memoria, archivos), no usar OCF provoca:

  * **Memory leaks**.
  * **Double-free** (intentar borrar la misma memoria dos veces).
  * **Shallow copy** (copias superficiales donde dos objetos pelean por el mismo recurso).

-----

### Implementación en la clase Fixed

Aquí está el esqueleto básico de cómo se ve esto en código:

#### 1\. Constructor por defecto

```cpp
Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}
```

  * Inicializa a 0. Simple.

#### 2\. Constructor de copia

```cpp
Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
    // Ojo: Aquí podés usar *this = other si querés reciclar lógica, 
    // pero la inicialización directa suele ser más eficiente.
}
```

  * Se llama al **crear** un objeto desde otro: `Fixed b(a);` o `Fixed b = a;`.

#### 3\. Operador de asignación

```cpp
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &other) {  // 1. Protección contra auto-asignación (a = a)
        this->_value = other._value; // 2. Copia de valores
    }
    return *this;  // 3. Devuelve referencia para permitir a = b = c;
}
```

  * Se llama al **actualizar** un objeto ya existente: `a = b;`.

#### 4\. Destructor

```cpp
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
```

### ⚠️ Diferencia Clave: Constructor de Copia vs. Asignación

Es un error común confundirlos. Mira este ejemplo:

```cpp
Fixed a;        // Constructor por defecto
Fixed b(a);     // Constructor de copia (estás CREANDO b)
Fixed c = a;    // Constructor de copia (aunque haya un =, estás CREANDO c)

a = b;          // Operador de asignación (a ya existía, lo estás MODIFICANDO)
```

-----

## Ejercicio 01: Conversiones (Int / Float a Fixed)

### El concepto de Punto Fijo (Fixed Point)

Los `float` tienen el punto decimal "flotando" (se mueve según el exponente). En **Fixed Point**, el punto está clavado en una posición específica.

  * En nuestro caso: Usamos un `int` (32 bits).
  * **8 bits** para la parte fraccionaria.
  * **24 bits** para la parte entera (incluyendo el signo).

Esto significa que el valor real es:
$$ ValorReal = \frac{\text{RawValue}}{2^8} $$
O lo que es lo mismo:
$$ ValorReal = \frac{\text{RawValue}}{256} $$

### Implementación de Conversiones

#### De Entero a Fixed

Simplemente desplazamos los bits a la izquierda 8 posiciones (multiplicar por 256).

```cpp
Fixed::Fixed(const int nbr) {
    this->_value = nbr << _fractionalBits;
}
```

#### De Float a Fixed (Con redondeo)

Aquí está el truco. No podemos hacer bitshift con floats. Multiplicamos por 256 y usamos `roundf` para no perder precisión por truncamiento.

```cpp
Fixed::Fixed(const float nbr) {
    // nbr * 256, redondeado al entero más cercano
    this->_value = roundf(nbr * (1 << _fractionalBits));
}
```

#### De Fixed a Float

Operación inversa: dividimos por 256 (pero casteando a float para tener decimales).

```cpp
float Fixed::toFloat(void) const {
    return (float)this->_value / (float)(1 << _fractionalBits);
}
```

#### De Fixed a Entero

Simplemente desplazamos a la derecha (dividir por 256). Esto **trunca** los decimales.

```cpp
int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}
```

-----

### Roundf vs. Truncamiento: ¿Por qué importa?

  * **Truncamiento (`(int)x` o `floor`):** Corta los decimales sin piedad.
      * `3.9` → `3`
  * **Redondeo (`roundf`):** Busca el entero más cercano.
      * `3.9` → `4`

En el constructor `Fixed(float)`, usamos `roundf`.
**Ejemplo:** Queremos guardar `42.42`.

  * `42.42 * 256 = 10859.52`
  * Si truncamos (cast int): `10859` → `toFloat()` sería `42.4179` (Error mayor).
  * Si redondeamos (`roundf`): `10860` → `toFloat()` sería `42.4218` (Más preciso).

-----

## Deep Dive: Fixed vs. Float

Esta es la parte teórica "dura". ¿Por qué demonios querríamos usar Fixed Point si existen los `double`?

### Tabla Comparativa

| Característica | Float / Double | Fixed Point |
| :--- | :--- | :--- |
| **Precisión** | Variable (muy alta cerca del 0, baja en números grandes). | **Constante** en todo el rango. |
| **Exactitud** | Aproximada. `0.1 + 0.2` puede no ser `0.3`. | **Exacta**. Sabes exactamente qué números puedes representar. |
| **Rendimiento** | Lento en procesadores sin FPU (viejos o embebidos). | Muy rápido (son operaciones de enteros). |
| **Uso** | Ciencia, física, general. | Finanzas (dinero), juegos retro, embebidos. |

### ¿Qué significa que Fixed es "más predecible"?

Con Fixed (8 bits fraccionales), tu "unidad mínima" es $1/256 \approx 0.00390625$.
Cualquier número que guardes es **un múltiplo exacto** de ese valor. No hay sorpresas ocultas en el bit 50 de una mantisa.

  * **Float:** "Guárdame algo parecido a 1234.4321".
  * **Fixed:** "Guárdame exactamente 316014 unidades de 1/256".

-----

## Bonus Track: Operadores de Incremento (Ejercicio 02)

Aunque esto suele ser del siguiente ejercicio, tus apuntes lo mencionan. Es vital entender la diferencia entre `++i` y `i++`.

### 1\. Pre-incremento (`++a`)

Incrementa y *luego* devuelve el objeto. Es más eficiente (sin copias).

```cpp
Fixed& Fixed::operator++() {
    this->_value++; // Incrementa el valor raw (sumar 1/256 al real)
    return *this;   // Devuelve referencia a sí mismo
}
```

### 2\. Post-incremento (`a++`)

Tiene que devolver el valor *antiguo*, pero dejar el objeto incrementado. Requiere una copia temporal.

```cpp
// El 'int' es un dummy parameter para que el compilador distinga la firma
Fixed Fixed::operator++(int) {
    Fixed temp = *this; // Copia el estado actual
    ++(*this);          // Llama al pre-incremento
    return temp;        // Devuelve la copia antigua
}
```

-----

### Herramientas Útiles

#### Sobrecarga de `<<`

Para imprimir objetos `Fixed` con `std::cout`, usamos `toFloat()` porque queremos ver el número "humano", no el entero raw.

```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}
```

#### Calculadora `bc`

Si querés verificar tus cálculos en la terminal:

```bash
bc -l
obase=2
5.5 * 256   # Verás el binario
1408 / 256  # Verás 5.5
```

-----
