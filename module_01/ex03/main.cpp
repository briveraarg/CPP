/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:11:20 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 12:59:04 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		
		std::cout << "\n--- Ejemplo de SUBJECT ---\n" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std:: cout << "" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << "\n--- Ejemplo de Brendi ---" << std::endl;
		Weapon sword = Weapon("legendary katana");
		HumanA brendi("Brendi", sword);
		brendi.attack();
		sword.setType("flaming sword of doom");
		brendi.attack();
		
		std::cout << "\n--- sin arma inicial ---" << std::endl;
		HumanB brendiB("Brendi");
		brendiB.attack();
		Weapon bow = Weapon("enchanted bow");
		brendiB.setWeapon(bow);
		brendiB.attack();
		bow.setType("crossbow of precision");
		brendiB.attack();
	}
	return (0);
}
