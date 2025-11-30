
# 🧠 **ESQUEMA MENTAL DEL MÓDULO 04 — EN 5 BLOQUES**

# ➊ **"Hay un tipo de objeto que se comporta distinto según el hijo"**

👉 Eso es **POLIMORFISMO**.

**Animal**
→ `makeSound()` virtual
→ los hijos lo redefinen (Dog: ladrido / Cat: maullido)

**Clave mental:**

> *"Un puntero al padre puede ejecutar funciones del hijo."*

---

# ➋ **"Si NO uso virtual, el polimorfismo no funciona"*

👉 WrongAnimal / WrongCat

**Clave mental:**

> *"Sin virtual, el programa no sabe cuál función llamar."*

Se usa solo para mostrar el error.

---

# ➌ **"Perros y gatos tienen ideas → necesitan memoria dinámica"**

👉 Deep copy + Brain

Todos tienen :
`Brain* brain;`

**Clave mental:**

> *"Si hay punteros, hay que copiar profundo para evitar bugs."*
> *"Cada animal debe tener SU PROPIO cerebro."*

---

# ➍ **"Animal no debe poder existir solo"**

👉 Clase abstracta

MakeSound se vuelve:

```
virtual void makeSound() const = 0;
```

**Clave mental:**

> *"Clase abstracta = no instanciable + tiene métodos puros."*

---

# ➎ **"Sistema de magia estilo RPG"**

👉 Interfaces + Polimorfismo + Factoría + Deep Copy

## Materias (hechizos)

* **AMateria** → clase abstracta (tipo + clone + use)
* **Ice** → ataca
* **Cure** → cura

**Clave mental:**

> *"Cada magia es un hijo distinto con su propia acción."*

## Personajes (héroes)

* **Character**

  * 4 slots
  * equip / unequip / use
  * deep copy

**Clave mental:**

> *"El héroe usa materia, pero no la destruye al desequipar."*

## Fuente de magia (NPC)

* **MateriaSource**

  * aprende 4 materias
  * crea copias

**Clave mental:**

> *"Las materias no se crean con 'new Ice()', sino desde una fábrica."*

---

# **RESUMEN (para recordarlo siempre)**

> **“Hay animales polimórficos,
> cerebros que se copian profundamente,
> una clase base que no debe existir sola,
> materias mágicas que se clonan,
> personajes que las equipan,
> y una fábrica que crea hechizos.”**

---

# 🌟 **VERSIÓN AÚN MÁS SIMPLE **

```
POLIMORFISMO → Animal / Dog / Cat
SIN VIRTUAL → WrongAnimal (error)
DEEP COPY → Brain dentro de Dog/Cat
ABSTRACTO → Animal no puede existir
MAGIA → AMateria / Ice / Cure
PERSONAJE → Equipar y usar materias
FABRICA → MateriaSource crea copias
```

