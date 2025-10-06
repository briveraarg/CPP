/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:26:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 17:30:43 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
	std::string name;
	Weapon& weapon;  // REFERENCIA: siempre tiene arma, no puede cambiar

public:
	// Constructor: recibe nombre y referencia al arma
	HumanA(const std::string& humanName, Weapon& humanWeapon);
	
	// Destructor
	~HumanA();
	
	// Ataca con su arma
	void attack() const;
};

#endif
