/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:25:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 13:22:19 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

/*
 * getType: Devuelve referencia constante al tipo (no copia, no modificable)
 * setType: Establece nuevo tipo de arma
*/

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(const std::string& weaponType);
		~Weapon();

		const std::string& getType() const;
		void setType(const std::string& newType);
};

#endif
