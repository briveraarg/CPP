/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:26:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 12:39:09 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon) 
	: name(humanName), weapon(humanWeapon)
{
}

HumanA::~HumanA()
{
}

/*
 * 
 * Método const: no modifica el estado del objeto HumanA
 * Solo lee atributos y llama a métodos const de Weapon
 */
 
void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	std::cout << "*BAAAANG!*" << std::endl;
}
