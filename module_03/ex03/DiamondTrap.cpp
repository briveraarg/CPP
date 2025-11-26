/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:20:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 18:03:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
 * Constructores de DiamondTrap
 * - Inicializan la parte ClapTrap virtual con el nombre "<name>_clap_name".
 * - Establecen los valores específicos de DiamondTrap:
 *   hitPoints = 100 (como FragTrap),
 *   energyPoints = 50 (como ScavTrap),
 *   attackDamage = 30 (como FragTrap).
 */


DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name", 100, 50, 30),
	  ScavTrap(),
	  FragTrap(),
	  _name("default")
{
	std::cout << "DiamondTrap " << BOLD << _name
			  << RESET << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name", 100, 50, 30),
	  ScavTrap(),
	  FragTrap(),
	  _name(name)
{
	std::cout << "DiamondTrap " << BOLD << _name
			  << RESET << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	  ScavTrap(other),
	  FragTrap(other),
	  _name(other._name)
{
	std::cout << "DiamondTrap " << BOLD << _name
			  << RESET << " copy constructor called" << std::endl;
}


DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap " << BOLD << this->_name
		<< RESET << " copy assignment operator called"
		<< std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << BOLD << this->_name 
		<< RESET << " destructor called" 
		<< std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << BOLD << this->_name 
		<< RESET << ", ClapTrap name: "
		<< BOLD << ClapTrap::_name << RESET
		<< std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
