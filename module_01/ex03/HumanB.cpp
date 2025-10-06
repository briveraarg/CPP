/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:27:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 17:32:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor: inicializa nombre, sin arma (nullptr)
HumanB::HumanB(const std::string& humanName) : name(humanName), weapon(nullptr)
{
}

// Destructor: el humano se desarma (no libera el arma porque no la posee)
HumanB::~HumanB()
{
}

// Asigna un arma (toma la dirección de la referencia)
void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

// Ataca si tiene arma, si no... ¡problema!
void	HumanB::attack() const
{
	if (weapon != nullptr)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with!" << std::endl;
}
