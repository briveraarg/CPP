# 📚 WIKI - CPP Module 00 Ex02: Account Class

## 🎯 **Objetivo del Ejercicio**
Implementar una clase `Account` que simule cuentas bancarias usando **variables y métodos estáticos** para mantener información global compartida entre todas las instancias.

---

## 🧠 **Conceptos Clave**

### 1. **Variables Estáticas (Static Variables)**

#### **¿Qué son?**
Variables que pertenecen a la **clase**, no a las instancias individuales. Son **compartidas** por todos los objetos de esa clase.

#### **Declaración en .hpp:**
```cpp
class Account {
private:
    static int _nbAccounts;          // Número total de cuentas
    static int _totalAmount;         // Dinero total en todas las cuentas
    static int _totalNbDeposits;     // Depósitos totales realizados
    static int _totalNbWithdrawals;  // Retiros totales realizados
};
```

#### **Inicialización en .cpp:**
```cpp
// ⚠️ IMPORTANTE: Las variables estáticas DEBEN inicializarse fuera de la clase
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
```

#### **¿Por qué estáticas?**
- 📊 **Datos globales**: Necesitamos saber cuántas cuentas existen en total
- 💰 **Total de dinero**: Suma de todas las cuentas
- 📈 **Estadísticas**: Operaciones realizadas por todos los usuarios

---

### 2. **Métodos Estáticos (Static Methods)**

#### **¿Qué son?**
Métodos que pertenecen a la **clase**, no a instancias específicas. Pueden acceder solo a variables estáticas.

#### **Ejemplo:**
```cpp
static int getNbAccounts(void);     // Obtener número de cuentas
static int getTotalAmount(void);    // Obtener dinero total
static void displayAccountsInfos(void); // Mostrar info global
```

#### **Implementación:**
```cpp
int Account::getNbAccounts(void)
{
    return (_nbAccounts);  // ✅ Puede acceder a variables estáticas
    // return (_amount);   // ❌ ERROR: No puede acceder a variables de instancia
}
```

#### **¿Cómo se llaman?**
```cpp
// Desde la clase (sin objeto)
int total = Account::getNbAccounts();

// NO necesitas una instancia específica
Account acc1(100);
Account acc2(200);
std::cout << Account::getNbAccounts(); // Resultado: 2
```

---

### 3. **Variables de Instancia vs Estáticas**

| **Variable de Instancia** | **Variable Estática** |
|---------------------------|------------------------|
| `int _amount;` | `static int _totalAmount;` |
| Una por objeto | Una para toda la clase |
| `acc1._amount != acc2._amount` | `Account::_totalAmount` (compartida) |
| Se inicializa en constructor | Se inicializa fuera de la clase |

#### **Ejemplo práctico:**
```cpp
Account acc1(100);  // acc1._amount = 100, _totalAmount = 100
Account acc2(50);   // acc2._amount = 50,  _totalAmount = 150
```

---

### 4. **Constructor y Variables Estáticas**

#### **Lo que hace el constructor:**
```cpp
Account::Account(int initial_deposit)
{
    // Variables de instancia
    _accountIndex = _nbAccounts;  // Índice único para esta cuenta
    _amount = initial_deposit;    // Dinero de ESTA cuenta
    _nbDeposits = 0;             // Depósitos de ESTA cuenta
    _nbWithdrawals = 0;          // Retiros de ESTA cuenta
    
    // Variables estáticas (globales)
    _nbAccounts++;               // ¡Una cuenta más en total!
    _totalAmount += initial_deposit; // ¡Más dinero en el sistema!
}
```

#### **Secuencia de creación:**
```cpp
Account acc1(100);  // _nbAccounts=1, _totalAmount=100
Account acc2(50);   // _nbAccounts=2, _totalAmount=150
Account acc3(200);  // _nbAccounts=3, _totalAmount=350
```

---

### 5. **Timestamp con Tiempo Real**

#### **Implementación:**
```cpp
void Account::_displayTimestamp(void)
{
    std::time_t   rawtime;
    std::tm       *timeinfo;
    char          buffer[20];
    
    std::time(&rawtime);                    // Obtener tiempo actual
    timeinfo = std::localtime(&rawtime);    // Convertir a tiempo local
    
    // Formatear: [YYYYMMDD_HHMMSS]
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeinfo);
    std::cout << buffer;
}
```

#### **Librerías necesarias:**
```cpp
#include <ctime>    // Para std::time, std::localtime
#include <cstring>  // Para std::strftime
```

---

### 6. **Flujo de Datos en Operaciones**

#### **Depósito (makeDeposit):**
```cpp
void Account::makeDeposit(int deposit)
{
    int p_amount = _amount;  // Guardar cantidad anterior
    
    // Actualizar ESTA cuenta
    _amount += deposit;
    _nbDeposits++;
    
    // Actualizar totales GLOBALES
    _totalAmount += deposit;     // ¡Más dinero en el sistema!
    _totalNbDeposits++;         // ¡Una operación más!
    
    // Mostrar información
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}
```

#### **Retiro (makeWithdrawal):**
```cpp
bool Account::makeWithdrawal(int withdrawal)
{
    // ✅ Validación: ¿Hay suficiente dinero?
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);  // ❌ Operación rechazada
    }
    
    // ✅ Hay suficiente dinero, proceder
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;      // Menos dinero en el sistema
    _totalNbWithdrawals++;          // Una operación más
    
    return (true);  // ✅ Operación exitosa
}
```

---

### 7. **Orden de Destrucción (LIFO)**

#### **¿Por qué LIFO?**
Los objetos se destruyen en orden **inverso** a como se crearon:
```cpp
Account acc1(100);  // 1º creado
Account acc2(50);   // 2º creado
Account acc3(200);  // 3º creado
// Fin del programa:
// acc3.~Account();  // 1º destruido
// acc2.~Account();  // 2º destruido  
// acc1.~Account();  // 3º destruido
```

---

## 🔧 **Patrones de Diseño Aplicados**

### 1. **Singleton-like Pattern**
Las variables estáticas actúan como un "singleton" para datos globales.

### 2. **Factory Pattern**
Cada constructor "registra" automáticamente el objeto en el sistema global.

### 3. **Observer Pattern**
Cada operación "notifica" al sistema global actualizando contadores.

---

## 🚨 **Errores Comunes y Soluciones**

### ❌ **Error 1: No inicializar variables estáticas**
```cpp
// MAL - Variables estáticas sin inicializar
class Account {
    static int _nbAccounts;  // ❌ No inicializada
};

// BIEN - Inicializar en .cpp
int Account::_nbAccounts = 0;  // ✅ Inicializada
```

### ❌ **Error 2: Acceder a variables de instancia desde método estático**
```cpp
static int getAmount(void)
{
    return (_amount);  // ❌ ERROR: método estático no puede acceder a _amount
}
```

### ❌ **Error 3: Olvidar actualizar totales globales**
```cpp
void makeDeposit(int deposit)
{
    _amount += deposit;        // ✅ Actualiza cuenta individual
    // _totalAmount += deposit; // ❌ OLVIDO: No actualiza total global
}
```

---

## 📊 **Ejemplo Completo de Ejecución**

```cpp
Account acc1(100);  // _nbAccounts=1, _totalAmount=100
Account acc2(50);   // _nbAccounts=2, _totalAmount=150

acc1.makeDeposit(20);   // acc1: 120, _totalAmount=170, _totalNbDeposits=1
acc2.makeWithdrawal(10); // acc2: 40,  _totalAmount=160, _totalNbWithdrawals=1

Account::displayAccountsInfos();
// Output: accounts:2;total:160;deposits:1;withdrawals:1
```

---

## 💡 **¿Por qué es importante este ejercicio?**

1. **🏗️ Fundación para C++**: Variables estáticas son cruciales en programación avanzada
2. **🔄 Gestión de estado global**: Aprendes a manejar datos compartidos
3. **🧮 Contabilidad de recursos**: Patrón común en sistemas reales
4. **📊 Singleton pattern**: Base para patrones de diseño
5. **🎯 Encapsulación**: Datos privados con interfaz pública controlada

---

## 🏆 **Conceptos que dominas después de este ejercicio:**

- ✅ Variables y métodos estáticos
- ✅ Diferencia entre datos de instancia y clase
- ✅ Inicialización de variables estáticas
- ✅ Manejo de timestamps con `<ctime>`
- ✅ Validación de operaciones bancarias
- ✅ Patrón de conteo automático de instancias
- ✅ Orden de construcción/destrucción (LIFO)

---

**🎓 ¡Este ejercicio es la base para entender gestión de estado en C++!**
