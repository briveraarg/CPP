/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:45:32 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 18:00:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ------ constructors ------ */

AMateria::AMateria(void) :_type("default")
{
	std::cout << BOLD << "AMateria" << RESET
		<< " default contructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
   std::cout << BOLD << "AMateria (type: " << type << ")" << RESET
              << " default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other): _type(other._type)
{
	std::cout << BOLD << "AMateria" << RESET
		<< " copy contructor called" << std::endl;	
}

/* ------ operator = ------ */

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;
	std::cout << BOLD << "AMateria" << RESET
		<< "copy assigment operator called" << std::endl;
	return (*this);
}

/* ------ destructor ------ */

AMateria::~AMateria()
{
	std::cout << BOLD << "AMateria" << RESET
        << " destructor called" << std::endl;
}

/* ------ methodos ------ */

std::string const & AMateria::getType() const
{
	return (_type);
}

/*
 * Use de AMateria es un método virtual
 * No hace nada en la clase base.
 * Esta declaracion es solo para evitar el warning
 * de "unused parameter"
 *
*/

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
