/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:32 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 14:55:56 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

/*
 * 
 * Estructura de la clase Cat:
 * - Herencia:
 * 		Hereda públicamente de la clase Animal.
 * - Atributo privado:
 * 		Brain* _brain; // puntero a la clase Brain (composición).
 * - Constructores:
 * 		Cat() -> constructor por defecto (inicializa type a "Cat" y crea new Brain).
 * 		Cat(const Cat& other) -> constructor de copia (deep copy del Brain).
 * - Operador de asignación: 
 * 		operator=(const Cat& other) deep copy del Brain y llama al operador base.
 * - Destructor:
 * 		~Cat() libera la memoria del Brain (delete _brain).
 * - Métodos:
 * 		void makeSound() const;     // implementación específica del sonido ("meow!").
 * 		getIdeaCat/setIdeaCat;      // métodos específicos para acceder a ideas.
 * 		getBrain();                 // devuelve el puntero al cerebro.
 * 
*/

class Cat : public AAnimal
{
	private:
		Brain*	_brain;
	
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		~Cat();

		void			makeSound() const;
		std::string		getIdeaCat(size_t index) const;
		void			setIdeaCat(size_t index, const std::string& idea);
		Brain*			getBrain() const;
};

#endif