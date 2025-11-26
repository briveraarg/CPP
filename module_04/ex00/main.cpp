/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:37:28 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 12:15:28 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;
		std::cout << "meta type: " << meta->getType() << std::endl;
		
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;

		std::cout << "\n--- Wrong classes test (no virtual) ---" << std::endl;
		const WrongAnimal* wmeta = new WrongAnimal();
		const WrongAnimal* wcat = new WrongCat();

		std::cout << "wcat type: " << wcat->getType() << std::endl;
		wcat->makeSound(); // because makeSound is NOT virtual, this will call WrongAnimal::makeSound
		wmeta->makeSound();

		delete wmeta;
		delete wcat;
	return 0;
}