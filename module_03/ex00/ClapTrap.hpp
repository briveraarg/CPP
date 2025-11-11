/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:28:39 by brivera           #+#    #+#             */
/*   Updated: 2025/11/11 19:08:50 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

/*
 * La Forma Canónica Ortodoxa (Orthodox Canonical Form):
 *  0. constructor por defecto  Fixed(void);
 * 	1. constructor de copia -> Fixed(const Fixed& other)
 *  2. operador de asignacion -> Fixed& operator=(const Fixed& other);
 *  3. destructor -> ~Fixed();
 * 
*/

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& name);

		ClapTrap& operator=(const ClapTrap& other);

		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif