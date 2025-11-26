/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:37:28 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 14:14:50 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
		std::cout << BOLD << BRIGHT_GREEN << "------ ex00 ------" << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << BOLD << BRIGHT_GREEN << "------ type ------" << RESET << std::endl;
		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;
		std::cout << "meta type: " << meta->getType() << std::endl;
		
		std::cout << BOLD << BRIGHT_GREEN << "------ sound ------" << RESET << std::endl;
		std::cout << "i type: " << i->getType() << " -> ";
		i->makeSound();
		std::cout << "j type: " << j->getType() << " -> ";
		j->makeSound();
		std::cout << "meta type: " << meta->getType() << " -> ";
		meta->makeSound();

		std::cout << BOLD << BRIGHT_GREEN << "------ destructor ------" << RESET << std::endl;
		delete meta;
		delete j;
		delete i;

		std::cout << BOLD << BRIGHT_BLUE << "\n--- Wrong classes test (no virtual) ---" << RESET << std::endl;
		const WrongAnimal* wmeta = new WrongAnimal();
		const WrongAnimal* wcat = new WrongCat();

		std::cout << BOLD << BRIGHT_BLUE << "------ sound ------" << RESET << std::endl;
		std::cout << "wcat type: " << wcat->getType() << " -> ";
		wcat->makeSound(); // because makeSound is NOT virtual, this will call WrongAnimal::makeSound
		std::cout << "wmeta type: " << wmeta->getType() << " -> ";
		wmeta->makeSound();

		std::cout << BOLD << BRIGHT_BLUE << "------ destructor ------" << RESET << std::endl;
		delete wmeta;
		delete wcat;
	return 0;
}