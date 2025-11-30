/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:38:20 by brivera           #+#    #+#             */
/*   Updated: 2025/11/30 20:08:53 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ------ Constructors ------ */

Character::Character(void) : _name("defaultName")
{
	// std::cout << BOLD << "Character" << RESET
	//		<< " default contructor called" << std::endl;
	for(int i = 0; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	// std::cout << BOLD << "Character" << RESET
	//		<< " contructor PARAMETRIZADO called" << std::endl;
	for(int i = 0; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character & other) : _name(other._name)
{
	// std::cout << BOLD << "Character" << RESET
	//		<< " copy contructor called" << std::endl;
	for(int i = 0; i < MAX_SLOT; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else 
			this->_inventory[i] = NULL;
	}
}

/* ------ Destructor ------ */

Character::~Character()
{
	// std::cout << BOLD << "Character" << RESET
	//		<< " destructor called" << std::endl;
	for(int i = 0; i < MAX_SLOT; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/* ------ Operators ------ */

Character& Character::operator=(const Character& other)
{
	// std::cout << BOLD << "Character" << RESET
	// 		<< " copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		for(int i = 0; i < MAX_SLOT; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}	
		}
		for(int i = 0; i < MAX_SLOT; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

/* ------ Methods ------ */

std::string const & Character::getName() const
{
	return (this->_name);
}

/*
 * Que pasa si el inventario está lleno??
 * OJO: El subject dice "nothing should happen",
 * pero si no hacemos nada con 'm',
 * se perderá la referencia y habrá leak si fue creado con new.
 * Normalmente en este ejercicio se asume que el main gestiona eso, 
 * o simplemente no hacemos nada como dice el subject.
 * 
 */

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Equipped " << m->getType()
				<< " in slot " << i << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_SLOT && this->_inventory[idx])
	{
		std::cout << "Unequipped " << this->_inventory[idx]->getType()
			<< " from slot " << idx << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MAX_SLOT && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
