
# **ESQUEMA MENTAL DEL MÓDULO 04**

### Hay un tipo de objeto que se comporta distinto según el hijo

Eso es **POLIMORFISMO**.

**Animal**
→ `makeSound()` virtual
→ los hijos lo redefinen (Dog: ladrido / Cat: maullido)

**Clave mental:**

> *Un puntero al padre puede ejecutar funciones del hijo.*

---

### Si NO uso virtual, el polimorfismo no funciona*

WrongAnimal / WrongCat

**Clave mental:**

> *Sin virtual, el programa no sabe cuál función llamar.*

Se usa solo para mostrar el error.

---

### **Perros y gatos tienen ideas → necesitan memoria dinámica**

Deep copy + Brain

Todos tienen :
`Brain* brain;`

**Clave mental:**

> *"Si hay punteros, hay que copiar profundo para evitar bugs."*
> *"Cada animal debe tener SU PROPIO cerebro."*

---

### **Animal no debe poder existir solo**

Clase abstracta

MakeSound se vuelve:

```
virtual void makeSound() const = 0;
```

**Clave mental:**

> *"Clase abstracta = no instanciable + tiene métodos puros."*

---

### **Sistema de magia**

Interfaces + Polimorfismo + Factoría + Deep Copy

### Materias (hechizos)

* **AMateria** → clase abstracta (tipo + clone + use)
* **Ice** → ataca
* **Cure** → cura

**Clave mental:**

> *Cada magia es un hijo distinto con su propia acción.*

### Personajes (héroes)

* **Character**

  * 4 slots
  * equip / unequip / use
  * deep copy

**Clave mental:**

> *El héroe usa materia, pero no la destruye al desequipar.*

### Fuente de magia

* **MateriaSource**

  * aprende 4 materias
  * crea copias

**Clave mental:**

> *Las materias no se crean con 'new Ice()', sino desde una fábrica.*

---

### **RESUMEN **

> **“Hay animales polimórficos,
> cerebros que se copian profundamente,
> una clase base que no debe existir sola,
> materias mágicas que se clonan,
> personajes que las equipan,
> y una fábrica que crea hechizos.”**


## Que es eso de clone? como funciona? 
1. **Copiar un personaje → copia profunda de las materias del inventario**
2. **MateriaSource crea materias usando clone()**

---

## PRIMERO: ¿QUÉ ES REALMENTE `clone()`?

En AMateria:

```cpp
virtual AMateria* clone() const = 0;
```

Esto significa:

* **AMateria no implementa clone()**
* Solo declara que *todas las hijas* deben implementarlo
* El compilador garantiza que **llamar clone() desde un puntero AMateria siempre va a ejecutar la versión correcta de la clase hija**

---

## En Ice:

```cpp
AMateria* Ice::clone() const {
    return new Ice(*this);
}
```

Esto crea un **nuevo objeto Ice** copiando *este*.

---

## En Cure:

```cpp
AMateria* Cure::clone() const {
    return new Cure(*this);
}
```

Esto crea un **nuevo Cure** copiando *este*.

---


### **SI COPIO UN PERSONAJE → ¿Cómo se clonan sus materias?**

Imaginemos este personaje:

```
me.inventory = [ Ice*, Cure*, empty, empty ]
```

Y hacés:

```cpp
Character tmp = me;
```

Entonces entra el **copy constructor** de Character.

Este constructor debe hacer:

```cpp
for (int i = 0; i < 4; i++) {
    if (other.inventory[i] != NULL) {
        this->inventory[i] = other.inventory[i]->clone();
    } else {
        this->inventory[i] = NULL;
    }
}
```

### ¿Qué pasa aquí realmente?

El compilador ve:

```
other.inventory[i] → puntero AMateria*
```

Pero ese puntero **en realidad** apunta a:

* un Ice
* o un Cure

Entonces cuando vos llamás:

```
other.inventory[i]->clone()
```

EL COMPILADOR NO ELIGE LA FUNCIÓN.

**Elige en tiempo de ejecución**
por la palabra clave **virtual**.

El CPU mira el objeto real en memoria y ejecuta:

* `Ice::clone()` si es un Ice
* `Cure::clone()` si es un Cure

Emitimos un diagrama:

```
AMateria* ptr → (en realidad) Ice

ptr->clone()
      ↓
Ejecuta Ice::clone()
      ↓
new Ice(*this)
```

  Por eso se llama **polimorfismo dinámico**.

---

### **Resultado: el personaje copia PROFUNDAMENTE cada materia**

Así queda la memoria:

```
Original:
   inventory[0] → Ice (A)
   inventory[1] → Cure (A)

Copia:
   inventory[0] → Ice (B)  ← nuevo objeto creado por clone()
   inventory[1] → Cure (B) ← nuevo objeto creado por clone()
```

No comparten la misma materia.
Cada una es nueva.

---
