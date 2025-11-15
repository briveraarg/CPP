# Tema del módulo 03: Inheritance

Este módulo trata sobre cómo una clase puede heredar de otra, compartiendo sus atributos y comportamientos, y cómo extenderlos o modificarlos.

## Nota sobre ex00 - ClapTrap

- Clase implementada: `ClapTrap` (archivo `ex00/ClapTrap.hpp` / `ClapTrap.cpp`).
- Atributos clave: `name`, `hitPoints` (inicial 10), `energyPoints` (inicial 10), `attackDamage` (inicial 0).
- Constructores: se incluyen constructor por defecto, constructor con `name` y constructor de copia. Además se implementó operador= y destructor (Rule of Three).
- Mensajes: se añadieron mensajes informativos en constructores, destructor y en los métodos `attack`, `takeDamage`, `beRepaired` para facilitar la validación manual.
- Seguridad: se añadió comprobación para evitar underflow cuando se resta daño a `hitPoints` (si `amount >= hitPoints` se deja en 0).
- Colores: el proyecto usa macros ANSI para colorear la salida opcionalmente; se recomienda usarlos usando `<< BRIGHT_BLUE << name << RESET <<` (no concatenarlos como literales adyacentes).
- Tests: `ex00/main.cpp` contiene pruebas manuales que ejercitan ataques, reparación, agotamiento de energía, muerte y copia/assign.

¿Por qué 3 constructores?

Constructor por defecto (ClapTrap()): crea un objeto con valores iniciales por defecto (útil cuando no conoces el nombre o para crear arrays/containers).
Constructor parametrizado (ClapTrap(const std::string &name)): te permite crear una instancia con un nombre específico.
Constructor de copia (ClapTrap(const ClapTrap &other)): define cómo se copia un objeto a otro (necesario para copias correctas de estado).
Esto encaja con la llamada "Rule of Three" en C++98: si implementas manualmente cualquiera de (destructor, constructor de copia, operador=), normalmente debes implementar los otros dos. En tu código tienes también el operador= y el destructor, así que estás respetando la regla.


## Conceptos teóricos y notas extensas (ejercicio ClapTrap / ScavTrap)

Este apartado recoge los conceptos clave que se aplican en el ejercicio, explicados en español con ejemplos y notas prácticas.

1) Relación IS-A (Herencia)
- Cuando declares `class ScavTrap : public ClapTrap` decimos que "ScavTrap es un ClapTrap" (IS-A). El subobjeto `ClapTrap` forma parte del objeto `ScavTrap`.
- Por eso puedes usar un `ScavTrap` donde se espere un `ClapTrap*` o `ClapTrap&` (conversión implícita derivado→base).

2) Punteros/Referencias vs Objetos por valor
- `ClapTrap* p = new ScavTrap("G");` almacena la dirección del objeto `ScavTrap` en un puntero a la base `ClapTrap*`.
- `ClapTrap c = ScavTrap("G");` provoca slicing: se copia sólo la parte `ClapTrap` en `c` y se pierde la parte derivada `ScavTrap`.
- Usar referencias (`ClapTrap& r = s;`) permite acceder al objeto derivado sin slicing.

3) Polimorfismo y `virtual`
- Declarar un método en la base como `virtual` (por ejemplo `virtual void attack(...)`) permite que llamadas realizadas a través de punteros/referencias a la base ejecuten la implementación de la clase derivada en tiempo de ejecución.
- Esto es imprescindible si quieres escribir código genérico que trate objetos distintos a través de la interfaz base (
	p.ej. contenedores de `ClapTrap*` que almacenen `ScavTrap*`, `FragTrap*`, etc.).

4) Destructor virtual
- Si vas a borrar objetos derivados a través de punteros a la base (`delete p` donde `p` es `ClapTrap*` apuntando a un `ScavTrap`), el destructor de la base debe ser `virtual`.
- Si `~ClapTrap()` no es virtual, `delete p` desencadena comportamiento indefinido: el destructor derivado no se llamará y podrías provocar fugas o estados inconsistentes.

5) Orden de construcción y destrucción
- Construcción: primero se construyen los subobjetos base (ClapTrap), luego los miembros directos de la clase derivada (ScavTrap), y finalmente se ejecuta el cuerpo del constructor derivado.
- Destrucción: orden inverso — primero el cuerpo del destructor derivado, luego el destructor base.

6) Inicialización de miembros y lista de inicializadores
- En la lista de inicializadores del constructor de `ScavTrap` puedes inicializar:
	- subobjetos base: `ScavTrap(): ClapTrap("name") {}`
	- miembros declarados en `ScavTrap` (ej: `_specialFlag(true)`).
- No puedes inicializar directamente miembros declarados en la clase base (ej: `_hitPoints`) desde la lista de inicializadores de `ScavTrap` — esos deben inicializarse por el constructor de `ClapTrap`.
- Si quieres establecer valores concretos en la parte base, la opción idiomática es añadir un constructor parametrizado en `ClapTrap` que reciba (name, hp, ep, ad) y llamarlo desde `ScavTrap`.

7) Rule of Three (copiar/assign/destruir)
- Cuando implementas destructor, copia u operador= manualmente, debes considerar los tres. Esto es importante si tu clase gestiona recursos (memoria dinámica, handles, etc.).
- En este ejercicio, ClapTrap implementa los tres para controlar mensajes y copia de estado simple.

8) Slicing (corte)
- `ClapTrap c = ScavTrap("G");` compila porque hay un constructor de copia/convertidor desde `ScavTrap` a `ClapTrap` implícito, pero el objeto resultante `c` es sólo la parte base. Evita hacerlo si necesitas el comportamiento derivado.

9) Conversión de punteros y ajustes (offsets)
- En herencia simple, la dirección del subobjeto base suele coincidir con la dirección del objeto derivado (offset 0), por eso `ClapTrap* p = s` donde `s` es `ScavTrap*` apunta al mismo bloque de memoria.
- En herencia múltiple/virtual, el compilador puede ajustar el puntero (añadir offset). El ajuste lo realiza el compilador en la conversión implícita.

10) vptr / vtable (muy breve)
- Los métodos virtuales usan una tabla de despacho (vtable). Cada objeto que tiene métodos virtuales suele contener un puntero implícito (vptr) a esa tabla.
- La vtable permite resolver qué implementación concreta ejecutar en tiempo de ejecución.

11) Administración de memoria: `new` / `delete`
- `new ScavTrap("G")` reserva memoria en el heap y llama a los constructores. `delete p` invoca el destructor correspondiente y libera memoria.
- En C++98 no hay smart pointers en la librería estándar; gestiona `delete` manualmente o evita `new` cuando sea posible (usar objetos en pila y referencias).

12) Buenas prácticas aplicadas en el ejercicio
- Hicimos miembros `protected` en `ClapTrap` cuando la derivada necesitaba acceder/ajustar valores iniciales.
- Hicimos `attack` `virtual` para que `ScavTrap::attack` se ejecute a través de punteros/referencias a la base.
- Hicimos `~ClapTrap` `virtual` para asegurar destrucción correcta.
- Añadimos comprobaciones defensivas (HP/EP) para evitar underflow en unsigned ints.

13) Ejemplos de uso y efectos en `main.cpp`
- `ClapTrap* p = new ScavTrap("Guardian"); p->attack("x"); delete p;` demuestra polimorfismo y destructores virtuales.
- `ClapTrap c = ScavTrap("G");` demuestra slicing (pérdida de la parte derivada).
- `ClapTrap& r = s;` (referencia) evita slicing y permite polimorfismo.

14) Posibles mejoras/extensiones
- Añadir un constructor parametrizado en `ClapTrap` para inicializar hp/ep/ad desde la lista de inicializadores en `ScavTrap`.
- Implementar `_guardMode` booleano en `ScavTrap` para que `guardGate()` cambie estado en vez de sólo imprimir.
- Agregar getters `getHitPoints()` / `getEnergyPoints()` para depuración y pruebas.
- En C++ moderno, usar `std::unique_ptr<ClapTrap>` en lugar de `new`/`delete`.

15) Resumen práctico (qué recordar)
- Usa punteros/referencias para polimorfismo; no uses copia por valor si quieres preservar comportamiento derivado.
- Declara destructor virtual en la clase base si hay herencia y borrado por puntero a la base.
- Inicializa la parte base en la lista de inicializadores llamando al constructor de la base cuando necesites establecer valores concretos de la base.

---



