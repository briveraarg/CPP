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

