/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:24 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 14:55:37 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>

/*
 * 
 * Estructura de la clase Dog:
 * - Herencia:
 * 		Hereda públicamente de la clase Animal.
 * - Atributo privado:
 * 		Brain* _brain; // puntero a la clase Brain (composición).
 * - Constructores:
 * 		Dog() -> constructor por defecto (inicializa type a "Dog" y crea new Brain).
 * 		Dog(const Dog& other) -> constructor de copia (deep copy del Brain).
 * - Operador de asignación: 
 * 		operator=(const Dog& other) deep copy del Brain y llama al operador base.
 * - Destructor:
 * 		~Dog() libera la memoria del Brain (delete _brain).
 * - Métodos:
 * 		void makeSound() const;     // implementación específica del sonido ("woof!").
 * 		getIdeaDog/setIdeaDog;      // métodos específicos para acceder a ideas.
 * 		getBrain();                 // devuelve el puntero al cerebro.
 * 
*/

class Dog : public AAnimal
{
	private:
		Brain*	_brain;
	
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		~Dog();
		
		void    		makeSound() const;
		std::string		getIdeaDog(size_t index) const;
		void			setIdeaDog(size_t index, const std::string& idea);
		Brain*			getBrain() const;

};

#endif