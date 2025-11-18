
# Módulo 00 - primera vez con c++

## Parte 1: IOManips (Input/Output Manipulators)

### ¿Qué son los IOManips?

Son el "maquillaje" de tu consola. Son funciones dentro de la librería `<iomanip>` que modifican cómo el stream (`cout`) presenta los datos. Sin ellos, el texto sale crudo; con ellos, podés hacer tablas y reportes profesionales.

```cpp
#include <iomanip>  // ¡Obligatoria para usar setw, setprecision, etc.!
```

### 🎨 El "Kit de Maquillaje" Principal

#### 1\. Ancho y Relleno (Padding)

Fundamental para alinear columnas.

```cpp
// Sin formato
std::cout << "H" << "ola" << std::endl; // "Hola"

// Con setw (Set Width) - Reserva espacio
std::cout << std::setw(10) << "Hola" << std::endl;       // "      Hola" (Alineado derecha por defecto)
std::cout << std::left << std::setw(10) << "Hola";       // "Hola      " (Alineado izquierda)

// Con setfill - Cambia el espacio vacío por un carácter
std::cout << std::setfill('.') << std::setw(10) << "Hola"; // "......Hola"
```

#### 2\. Números Flotantes

Control total sobre los decimales.

```cpp
double pi = 3.14159265359;

std::cout << std::setprecision(4) << pi << std::endl;                // 3.142 (Redondea y cuenta dígitos totales)
std::cout << std::fixed << std::setprecision(2) << pi << std::endl;  // 3.14  (Fija 2 decimales estrictos)
```

### 🧉 La Analogía del Mate

Los IOManips son como las instrucciones para cebar un buen mate:

```cpp
std::cout << std::setfill('~')      // "Llenamos los huecos con yerbita (~)"
          << std::setw(10)          // "Usamos un mate de 10cm de boca"  
          << std::right             // "La bombilla a la derecha"
          << "MATE"                 // "Ponemos el agua"
          << std::endl;             // Resultado: "~~~~~~MATE"
```

### 🧪 Ejemplo Práctico: Tabla de Evaluación 42

Este es el uso más común en los ejercicios de la escuela: mostrar logs ordenados.

```cpp
#include <iostream>
#include <iomanip>

int main() {
    // Separador
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' '); // ¡Importante! Restaurar el relleno a espacio

    // Cabecera
    std::cout << "| " << std::left << std::setw(10) << "Ejercicio" 
              << "| " << std::right << std::setw(8) << "Estado" 
              << " |" << std::endl;

    // Separador
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');

    // Filas
    std::cout << "| " << std::left << std::setw(10) << "ex00" 
              << "| " << std::right << std::setw(8) << "OK" 
              << " |" << std::endl;

    return 0;
}
```

-----

## Parte 2: La Clase Account (Static Members)

### 🎯 Objetivo del Ejercicio 02

Este ejercicio simula un banco global. El desafío no es la lógica bancaria, sino entender **dónde se guardan los datos**.

  * Cada cuenta sabe cuánto dinero tiene (**Instancia**).
  * El banco sabe cuánto dinero tienen *todos* los clientes juntos (**Estático**).

### 1\. Variables Estáticas vs. De Instancia

#### **Variables de Instancia (`_amount`)**

  * Pertenecen al **OBJETO**.
  * Si creas 10 cuentas, hay 10 variables `_amount` distintas en la memoria.
  * `acc1._amount` es diferente de `acc2._amount`.

#### **Variables Estáticas (`_totalAmount`)**

  * Pertenecen a la **CLASE**.
  * Si creas 10 cuentas, **solo existe 1 variable** `_totalAmount` en toda la memoria.
  * Es como una pizarra compartida en la pared: todos los objetos pueden leerla y escribir en ella.

### 2\. Implementación "Tricky"

#### Declaración (.hpp) vs. Inicialización (.cpp)

Las variables estáticas son especiales: se declaran dentro de la clase, pero **se inicializan fuera**, en el archivo `.cpp`, como si fueran variables globales pero con el prefijo `Account::`.

```cpp
// En Account.hpp
class Account {
    static int _nbAccounts; // Solo declaración
};

// En Account.cpp (¡FUERA DE CUALQUIER FUNCIÓN!)
int Account::_nbAccounts = 0; // Asignación de memoria real
```

### 3\. El Constructor "Mágico"

Cada vez que haces `Account a(100)`, el constructor actualiza tanto al individuo como al colectivo.

```cpp
Account::Account(int initial_deposit) {
    // 1. Trabajo Local (Instancia)
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    
    // 2. Trabajo Global (Estático)
    _totalAmount += initial_deposit; // Sumamos a la bóveda global del banco
    _nbAccounts++;                   // Contamos un cliente más
    
    // ¡Tip!: _accountIndex es útil para saber "quién soy" en el log
    this->_accountIndex = _nbAccounts - 1; 
}
```

### 4\. Métodos Estáticos (Getters Globales)

Un método `static` **no tiene** puntero `this`.

  * ✅ Puede acceder a `_totalAmount` (Variable estática).
  * ❌ **NO** puede acceder a `_amount` (Variable de instancia). ¿Por qué? Porque si llamas a `Account::getAmount()`, el programa no sabe de *qué* cuenta estás hablando.

<!-- end list -->

```cpp
int Account::getNbAccounts(void) {
    return _nbAccounts; // ✅ OK
}
```

### 5\. El Timestamp (Maldito `strftime`)

El ejercicio pide un log con la hora exacta. Aquí tenés el snippet estándar para no sufrir:

```cpp
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    char buffer[20];

    // Formato requerido: [AAAAMMDD_HHMMSS]
    std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", ltm);
    std::cout << buffer;
}
```

### 6\. Destrucción y LIFO (Last In, First Out)

Como las cuentas se crean en el `main` (en la Stack), se destruyen en orden inverso.

1.  Se crea `acc1` (Index 0).
2.  Se crea `acc2` (Index 1).
3.  ...fin del programa...
4.  Se destruye `acc2`.
5.  Se destruye `acc1`.

El destructor debe actualizar los globales (restar el dinero y bajar el contador de cuentas) para cerrar el banco limpiamente.

