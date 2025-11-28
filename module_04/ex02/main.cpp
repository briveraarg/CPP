/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:46:18 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 15:26:04 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main()
{
	std::cout << BOLD << BRIGHT_CYAN << "------ ex02 ------" << RESET << std::endl;
	
	// Intentamos instanciar AAnimal (debería dar error)
	// const AAnimal* animal = new AAnimal();
	
	Dog* luli = new Dog();
	Cat* naza = new Cat();

	luli->setIdeaDog(0, "Tengo hambre");
	naza->setIdeaCat(0, "Me voy a dormir");
	naza->setIdeaCat(-3, "lalalalalalalala");
		
	std::cout << BOLD << BRIGHT_CYAN << "------ tipo, ideas y makeSound ------" << RESET << std::endl;
	std::cout << "tipo naza: " << naza->getType() << std::endl;
	std::cout << "tipo luli: " << luli->getType() << std::endl;

	std::cout << "idea naza: " << naza->getIdeaCat(0) << std::endl;
	std::cout << "idea naza: " << naza->getIdeaCat(2) << std::endl;
	std::cout << "makeSound Naza: "; 
	naza->makeSound();
	std::cout << "idea luli: " << luli->getIdeaDog(0) << std::endl;
	std::cout << "idea luli: " << luli->getIdeaDog(-3) << std::endl;
	std::cout << "makeSound Luli: "; 
	luli->makeSound();
	std::cout << BOLD << BRIGHT_CYAN << "------ cerebro ------" << RESET << std::endl;

	Cat basic;
	{
		Cat tmp = basic;
		std::cout << "direccion cerebro basic: " << basic.getBrain() << std::endl;
		std::cout << "direccion cerebro tmp:   " << tmp.getBrain() << std::endl;
		if (basic.getBrain() != tmp.getBrain())
			std::cout << BOLD << BRIGHT_GREEN << "Copia profunda confirmada: Las direcciones de memoria son diferentes." << RESET << std::endl;
		else
			std::cout << BOLD << BRIGHT_RED << "Copia superficial detectada: Las direcciones de memoria son iguales!" << RESET << std::endl;
	}
	
	std::cout << BOLD << BRIGHT_CYAN << "------ destructor ------" << RESET << std::endl;
	delete naza;
	delete luli;

	std::cout << BOLD << BRIGHT_CYAN << "------ Prueba Array (Requisito del Subject) ------" << RESET << std::endl;
	const int N = 4;
	AAnimal* animals[N];

	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
		{
			Dog* d = new Dog();
			d->setIdeaDog(0, "Soy un perro");
			d->makeSound();
			animals[i] = d;
		}
		else
		{
			Cat* c = new Cat();
			c->setIdeaCat(0, "Soy un gato");
			c->makeSound();
			animals[i] = c;
		}
	}

	std::cout << " -----> Borrando array..." << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];
	return (0);
}
