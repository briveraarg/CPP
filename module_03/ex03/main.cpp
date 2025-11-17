/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:20:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 15:30:36 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


/*
 * main - pruebas para DiamondTrap
 * - Construction test: crea un DiamondTrap y muestra el orden de construcción.
 * - Abilities: invoca attack (delegado a ScavTrap), highFivesGuys (FragTrap),
 *   guardGate (ScavTrap) y whoAmI (DiamondTrap).
 * - Copy/Assign test: prueba constructor de copia y operador=, y verifica
 *   que las habilidades heredadas funcionan correctamente.
 */

int main()
{
	std::cout << BOLD << BRIGHT_CYAN << "-- DiamondTrap construction test --" << RESET << std::endl;
	DiamondTrap i("Iria");
	std::cout << std::endl;

	std::cout << BOLD << BRIGHT_CYAN << "-- DiamondTrap abilities --" << RESET << std::endl;
	i.attack("Ana");
	i.highFivesGuys();
	i.guardGate();
	i.whoAmI();

	std::cout << BOLD << BRIGHT_CYAN << "\n-- Copy/Assign test --" << RESET << std::endl;
	DiamondTrap d2 = i;
	d2.whoAmI();
	d2.attack("another enemy");

	std::cout << BOLD << BRIGHT_CYAN << "\n-- End --" << RESET << std::endl;
	return (0);
}
