/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:37:19 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 12:30:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap	Bren("Brendis");
	ClapTrap	Ana("Ana");
	ClapTrap	Oliver("Oli");
	int			i;

	std::cout << BOLD << BRIGHT_BLUE << "\n-- Basic Attacks --" << RESET << std::endl;
	Bren.attack("pew pew!");
	Ana.attack("ratatatata!");

	std::cout << BOLD << BRIGHT_BLUE << "\n-- Damage and Repair --" << RESET << std::endl;
	Bren.takeDamage(3);
	Bren.beRepaired(5);
	Ana.takeDamage(9);

	std::cout << BOLD << BRIGHT_BLUE << "\n-- Deplete Energy by Attacking --" << RESET << std::endl;
	i = 0;
	while (i < 12)
	{
		std::cout << BOLD << "[ " << i << " ]" << RESET << std::endl;
		Oliver.attack("bang!");
		Ana.attack("ratatatata!");
		i++;
	}
	std::cout << BOLD << BRIGHT_BLUE << "\n-- Ana: Attempt Repair --" << RESET << std::endl;
	Ana.takeDamage(12);
	Ana.beRepaired(2);

	std::cout << BOLD << BRIGHT_BLUE << "\n-- Copy and Assignment Tests --" << RESET << std::endl;
	ClapTrap copy = Oliver;
	copy.beRepaired(10);
	copy.attack("¡zaz!");

	ClapTrap assigned;
	assigned.attack("nothing");
	std::cout << BOLD << BRIGHT_BLUE << "\n-- Destructor --" << RESET << std::endl;
	return (0);
}