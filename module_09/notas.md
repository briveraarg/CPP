## Resumen rápido de los contenedores

* **ex00 → `std::map`** ✔️
* **ex01 → `std::stack`** ✔️
* **ex02 → `std::vector` + `std::list`** ✔️
---

## ex00 – `std::map` (Bitcoin Exchange) 

* Necesitás asociar **fecha → valor** → `map`
* `std::map` mantiene las claves **ordenadas automáticamente**.
* Problema del ejercicio:

  > “usar la fecha más cercana anterior si no existe”

Con `map` podés usar:

* `lower_bound()`
* `upper_bound()`
* y retroceder un iterador

---

## ex01 – `std::stack` (RPN)

Este es **literalmente un ejercicio de stack**.

* La notación polaca inversa se evalúa con:

  * push números
  * pop operandos
  * push resultados
* `std::stack` modela exactamente ese comportamiento LIFO.

> *std::stack es el contenedor natural para este problema.*



## ex02 – `std::vector` + `std::list` (PmergeMe)

### `std::vector`

* Acceso aleatorio rápido
* Muy eficiente en memoria
* Ideal para medir rendimiento con índices

### `std::list`

* Inserciones rápidas
* Sin acceso aleatorio
* Comportamiento muy distinto al vector → perfecto para comparar tiempos


📌 Ojo!!!:

* **Implementá el algoritmo dos veces**, uno para vector y otro para list
* No una función genérica con templates

  > el enunciado dice explícitamente que se aconseja evitarlas

--
