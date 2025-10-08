/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:27:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 12:51:31 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

// Recibe por referencia (evita copias y garantiza objeto válido)
// Guarda como puntero (permite flexibilidad y estados opcionales)

void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void	HumanB::attack() const
{
	if (weapon != NULL)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
		std::cout << "*SLASHHH!*" << std::endl;
	}
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}
