/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:26:25 by brivera           #+#    #+#             */
/*   Updated: 2025/11/13 16:54:37 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"),_hitPoints(10),
					 _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name),_hitPoints(10),
								 _energyPoint(10), _attackDamage(0)
{
	std::cout << "Constructor with name called " << name << std::endl;	
}
ClapTrap::ClapTrap(const ClapTrap& other):_name(other._name), _hitPoints(10),
		_energyPoint(10), _attackDamage(0)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

/* ============= */

void	ClapTrap::attack(const std::string& target)
{
	//if (this->_hitPoints <= 0)
	//	return ;
	//if (this->_energyPoint <= 0)
	//	return ;
	this->_energyPoint--;
	std::cout << "ClapTrap "
	<< this->_name << " attack " << target << ", causing "
	<< "cambiar" << " points of damage!" << std::endl;
}

