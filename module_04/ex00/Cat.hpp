/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:32 by brivera           #+#    #+#             */
/*   Updated: 2025/12/01 12:13:41 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

/*
 * 
 * Estructura de la clase Cat:
 * - Herencia:
 * 		Hereda públicamente de la clase Animal.
 * - Constructores:
 * 		Cat() -> constructor por defecto (inicializa type a "Cat").
 * 		Cat(const Cat& other) -> constructor de copia.
 * - Operador de asignación: 
 * 		operator=(const Cat& other) llama al operador de la base.
 * - Destructor:
 * 		~Cat() destructor específico.
 * - Métodos:
 * 		void makeSound() const;
 * 		// implementación específica del sonido ("meow!").
 * 
*/

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		~Cat();
		void	makeSound() const;
};
#endif