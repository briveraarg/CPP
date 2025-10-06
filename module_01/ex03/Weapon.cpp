/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:25:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 17:30:41 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& weaponType) : type(weaponType)
{
}

// Destructor: limpia el arma
Weapon::~Weapon()
{
}

// Devuelve referencia constante al tipo (eficiente, no copia)
const std::string& Weapon::getType() const
{
	return type;
}

// Cambia el tipo de arma
void Weapon::setType(const std::string& newType)
{
	type = newType;
}
