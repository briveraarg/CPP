/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:26:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 17:31:55 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor: inicializa nombre y referencia al arma
HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) 
	: name(humanName), weapon(humanWeapon)
{
}

// Destructor: el humano se desarma
HumanA::~HumanA()
{
}

// Ataca usando su arma (siempre tiene una)
void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
