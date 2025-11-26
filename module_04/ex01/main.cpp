/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:46:18 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 15:40:34 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	std::cout << BOLD << BRIGHT_MAGENTA << "------ ex01 ------" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << BOLD << BRIGHT_MAGENTA << "------ type ------" << RESET << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	std::cout << "meta type: " << meta->getType() << std::endl;
		
	std::cout << BOLD << BRIGHT_MAGENTA << "------ sound ------" << RESET << std::endl;
	std::cout << "i type: " << i->getType() << " -> ";
	i->makeSound();
	std::cout << "j type: " << j->getType() << " -> ";
	j->makeSound();
	std::cout << "meta type: " << meta->getType() << " -> ";
	meta->makeSound();

	std::cout << BOLD << BRIGHT_MAGENTA << "------ destructor ------" << RESET << std::endl;
	delete meta;
	delete j;
	delete i;

	return (0);
}
