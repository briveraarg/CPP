/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:26:25 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 16:49:13 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"),_hitPoints(10),
					 _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << BOLD << this->_name << RESET 
		<< " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name),_hitPoints(10),
								 _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << BOLD << this->_name <<
		RESET << " constructor called" << std::endl;    
}

ClapTrap::ClapTrap(const ClapTrap& other):
	_name(other._name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap " << BOLD << this->_name << 
				RESET << " copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name,
					unsigned int hp, unsigned int ep, unsigned int ad)
					: _name(name),
					_hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
	std::cout << "ClapTrap " << BOLD << this->_name << " custom constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
			<< " copy assignment operator called" << std::endl;
	}
	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << BOLD << this->_name << 
			 RESET << " destructor called" << std::endl;
}

/*
 * attack
 *  - Realiza un ataque hacia el objetivo indicado (representado como texto).
 *  - No modifica directamente a otros objetos ClapTrap (según el enunciado),
 *    sólo imprime un mensaje describiendo el ataque y decrementa
 *    los puntos de energía en 1 si el ClapTrap tiene puntos de vida y energía.
 *
 * Parámetros:
 *  - target: nombre o descripción del objetivo (no es otra instancia).
 */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
			<< " has no hit points and cannot attack." << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
			<< " has no energy points and cannot attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << BOLD << this->_name << RESET
				<< " attacks " << target << ", causing "
			  	BOLD << this->_attackDamage << RESET << " points of damage!" << std::endl;
}

/*
 * takeDamage
 *  - Aplica daño al ClapTrap: reduce los hit points en 'amount'.
 *  - Si 'amount' es mayor o igual que los hit points actuales, los hit
 *    points quedan en 0 (el ClapTrap "muere").
 *  - Se evita underflow comprobando antes de restar.
 *
 * Parámetros:
 *  - amount: cantidad de daño a aplicar (unsigned int).
 */

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
			<< " is already at 0 hit points." << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << BOLD << this->_name << RESET << " takes "
			BOLD << amount << RESET << " damage and has died." << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << BOLD << this->_name << RESET << " takes " 
				<< BOLD	<< amount << RESET << " damage, " 
			  	<< BOLD << this->_hitPoints << RESET << " hit points remaining." << std::endl;
}

/*
 * beRepaired
 *  - Repara (aumenta) los hit points en 'amount' y decrementa los
 *    puntos de energía en 1.
 *  - No puede repararse si está muerto (hitPoints == 0) o si no tiene
 *    energía suficiente.
 *
 * Parámetros:
 *  - amount: cantidad de vida a restaurar (unsigned int).
 */

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
				<< " has no energy points and cannot be repaired." << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << BOLD << this->_name << RESET
				<< " is dead and cannot be repaired." << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << BOLD << this->_name << RESET
				<< " is repaired by " << BOLD << amount << RESET << " points, "
			  	<< BOLD << this->_hitPoints << RESET << " hit points now." << std::endl;
}

