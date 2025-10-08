/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:27:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 12:46:13 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

/*
 * Weapon* weapon -> PUNTERO: puede no tener arma (nullptr)
 * HumanB(const std::string& humanName) -> Constructor: solo recibe nombre, sin arma inicial
 * 
*/

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(const std::string& humanName);
		~HumanB();
		
		void	setWeapon(Weapon& newWeapon);
		void	attack() const;
};

#endif
