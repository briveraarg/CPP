/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:24 by brivera           #+#    #+#             */
/*   Updated: 2025/11/27 18:57:40 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

/*
 * 
 * Estructura de la clase Dog:
 * - Herencia:
 * 		Hereda públicamente de la clase Animal.
 * - Constructores:
 * 		Dog() -> constructor por defecto (inicializa type a "Dog").
 * 		Dog(const Dog& other) -> constructor de copia.
 * - Operador de asignación: 
 * 		operator=(const Dog& other) llama al operador de la base.
 * - Destructor:
 * 		~Dog() destructor específico.
 * - Métodos:
 * 		void makeSound() const;     // implementación específica del sonido ("woof!").
 * 
*/

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        ~Dog();
        
        void    makeSound() const;
};

#endif