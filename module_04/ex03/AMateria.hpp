/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:35:20 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 20:23:51 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "color.hpp"

class ICharacter;

class AMateria
{
	private:
		std::string		_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& other);

		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
				
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif