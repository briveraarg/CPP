/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:28:39 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 11:56:31 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


/***************************************/
/*                COLOR                */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

/*
 * ClapTrap - implementación
 *
 * Constructores:
 *  - ClapTrap(): constructor por defecto. Inicializa name="default",
 *    hitPoints=10, energyPoints=10, attackDamage=0.
 *  - ClapTrap(const std::string& name): constructor con nombre.
 *  - ClapTrap(const ClapTrap& other): constructor de copia.
 *
 * Operador/Destructor:
 *  - operator=: copia el estado de otro ClapTrap protegiendo contra
 *    autoasignación.
 *  - ~ClapTrap(): destructor (no gestiona recursos dinámicos en este
 *    ejemplo, solo imprime un mensaje de seguimiento).
 *
 * Métodos principales:
 *  - void attack(const std::string& target): imprime un mensaje
 *    describiendo el ataque y decrementa energyPoints en 1 si el
 *    objeto tiene hitPoints>0 y energyPoints>0. No afecta a otros
 *    ClapTrap (según el enunciado del ejercicio).
 * 
 *  - void takeDamage(unsigned int amount): reduce hitPoints en
 *    'amount'. Si amount >= hitPoints, establece hitPoints a 0.
 *    Se evita underflow comprobando antes de restar.
 * 
 *  - void beRepaired(unsigned int amount): incrementa hitPoints en
 *    'amount' y decrementa energyPoints en 1. No funciona si
 *    hitPoints==0 o energyPoints==0.
 */

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap& name);
	
		ClapTrap& operator=(const ClapTrap& other);
		
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void 	beRepaired(unsigned int amount);
};

#endif