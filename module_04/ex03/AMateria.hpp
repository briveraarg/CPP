/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:35:20 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 17:29:09 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMETERIA_HPP

#include <iostream>
#include "color.hpp"
#include "ICharacter.hpp"

class AMateria
{
	private:
		std::string		_type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& other);

		AMateria& operator=(const AMateria& other);
		~AMateria();
				
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif