/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:25:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 17:30:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	// Constructor que recibe el tipo de arma
	Weapon(const std::string& weaponType);
	
	// Destructor
	~Weapon();
	
	// Devuelve referencia constante al tipo (no copia, no modificable)
	const std::string& getType() const;
	
	// Establece nuevo tipo de arma
	void setType(const std::string& newType);
};

#endif
