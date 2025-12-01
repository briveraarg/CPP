/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/01 12:19:54 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "color.hpp"

/*
 * 
 * Estructura de la clase Brain:
 * - Atributo privado:
 * 		std::string _ideas[100]; // array de 100 strings para almacenar ideas.
 * - Constructores:
 * 		Brain() -> constructor por defecto (inicializa ideas).
 * 		Brain(const Brain& other) -> constructor de copia (copia el array de ideas).
 * - Operador de asignación: 
 * 		operator=(const Brain& other) copia el contenido del array de ideas.
 * - Destructor:
 * 		~Brain() destructor de la clase.
 * - Métodos:
 * 		getIdeas(index) -> devuelve la idea en la posición index.
 * 		setIdea(index, idea) -> establece una idea en la posición index.
 * 
*/

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain& other);
		
		Brain&		operator=(const Brain& other);
		
		~Brain();

		std::string	getIdeas(size_t index) const;
		void		setIdea(size_t index, const std::string& idea);

};

#endif