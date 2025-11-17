/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 16:42:23 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* 
 * Valores que pide el subjet
 * this->_hitPoints = 100;
 * this->_energyPoints = 50;
 * this->_attackDamage = 20;
 * 
 * */

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "ScavTrap " << BOLD << this->_name
				<< RESET << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " destructor called" << std::endl;
}

/*
 * attack
 * - Intenta atacar al objetivo indicado por `target`.
 * - Requiere tener puntos de vida (> 0) y puntos de energía (> 0).
 * - Si dispone de energía, consume 1 punto de energía y muestra
 *   un mensaje indicando el daño causado (valor de `_attackDamage`).
 * - Según la especificación del ejercicio, no modifica directamente
 *   el estado del objetivo; sólo imprime la acción.
 */

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << BOLD << this->_name 
			<< RESET << " has no hit points and cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " has no energy points and cannot attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " attacks " << target << ", causing "
			<< BOLD << this->_attackDamage << RESET 
			<< " points of damage!" << std::endl;
}

/*
 * guardGate
 * - Activa el modo "Gate keeper" para este ScavTrap.
 * - Actualmente esta función sólo imprime un mensaje indicando
 * 	 que el ScavTrap ha entrado en modo guardián de la puerta.
*/
	
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << BOLD << this->_name
			<< RESET << " is now in Gate keeper mode."
			<< std::endl;
}
