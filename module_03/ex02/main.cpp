/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/15 18:05:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::cout << BOLD << BRIGHT_GREEN<< "-- Construction order test --" << RESET << std::endl;
	ClapTrap base("BaseC");
	FragTrap o("Oliver");

	std::cout << BOLD << BRIGHT_GREEN<< "\n-- FragTrap actions --" << RESET << std::endl;
	o.attack("target");
	o.highFivesGuys();
	o.takeDamage(40);
	o.beRepaired(20);

	std::cout << BOLD << BRIGHT_GREEN<< "\n-- Copy/Assign test --" << RESET << std::endl;
	FragTrap f2 = o;
	f2.highFivesGuys();

	FragTrap f3;
	f3 = f2;
	f3.attack("dummy");

	std::cout << BOLD << BRIGHT_GREEN<< "\n-- Polymorphism demo --" << RESET << std::endl;
	{
		ClapTrap *p = new FragTrap("FragPtr");
		p->attack("intruder");
		delete p;
	}

	std::cout << BOLD << BRIGHT_GREEN<< "\n-- End --" << RESET << std::endl;
	return (0);
}
