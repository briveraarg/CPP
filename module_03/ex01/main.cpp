/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/15 17:58:01 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << BOLD << BRIGHT_MAGENTA << "-- Construction order test --" << RESET << std::endl;
	ClapTrap b("Base");
	ScavTrap a("Ana");

	std::cout << BOLD << BRIGHT_MAGENTA << "\n-- ScavTrap actions --" << RESET << std::endl;
	a.attack("zaz!!");
	a.guardGate();
	a.takeDamage(30);
	a.beRepaired(10);

	std::cout << BOLD << BRIGHT_MAGENTA << "\n-- Copy/Assign test --" << RESET << std::endl;
	ScavTrap a2 = a;
	a2.attack("pew pew!");

	ScavTrap a3;
	a3 = a2;
	a3.guardGate();

	std::cout << BOLD << BRIGHT_MAGENTA << "\n-- Polymorphism demo --" << RESET << std::endl;
	{
		ClapTrap* p = new ScavTrap("Guardian");
		// Llamamos a attack() a través de un puntero a la base.
		// Gracias a `virtual`, se ejecutará ScavTrap::attack.
		p->attack("xxxxxxxx");
		// Al borrar vía puntero a la base, ambos destructores se llamarán
		// en el orden correcto (ScavTrap then ClapTrap) porque ~ClapTrap es virtual.
		delete p;
	}

	std::cout << BOLD << BRIGHT_MAGENTA << "\n-- End --" << RESET << std::endl;
	return (0);
}
