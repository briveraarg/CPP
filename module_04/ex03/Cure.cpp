/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:10:09 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 20:30:18 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

/* ------ Constructors ------ */

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	// std::cout << "Cure copy constructor called" << std::endl;
}

/* ------ Destructor ------ */

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

/* ------ Operators ------ */

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	// std::cout << "Cure assignment operator called" << std::endl;
	return (*this);
}

/* ------ Methods ------ */

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
