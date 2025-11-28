/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:20:13 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 16:14:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "color.hpp" 

/*
 * 
 * Estructura de la clase Animal:
 * - Atributo protegido:
 * 		std::string type;    // almacena el tipo/nombre del animal
 * - Constructores:
 * 		Animal() -> constructor por defecto (inicializa type a "Animal").
 * 		Animal(const std::string& type) -> constructor parametrizado
 * 		Animal(const Animal& other) -> constructor de copia.
 * - Operador de asignación: 
 * 		operator=(const Animal& other) copia el atributo type.
 * - Destructor virtual:
 * 		virtual ~Animal() para permitir destrucción polimórfica.
 * - Métodos:
 * 		std::string getType() const;         // devuelve el tipo
 * 		virtual void makeSound() const = 0;  // función virtual pura
 * 
*/

class	AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& other);

		AAnimal& operator=(const AAnimal& other);
	
		virtual ~AAnimal();

		std::string getType() const;
		virtual void makeSound() const = 0;

};

#endif