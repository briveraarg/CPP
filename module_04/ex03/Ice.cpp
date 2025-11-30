/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:10:49 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 20:30:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

/* ------ Constructors ------ */

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	// std::cout << "Ice copy constructor called" << std::endl;
}

/* ------ Destructor ------ */

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

/* ------ Operators ------ */

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	// std::cout << "Ice assignment operator called" << std::endl;
	return (*this);
}

/* ------ Methods ------ */

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
