/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:46:18 by brivera           #+#    #+#             */
/*   Updated: 2025/11/27 18:52:43 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main()
{
	std::cout << BOLD << BRIGHT_MAGENTA << "------ ex01 ------" << RESET << std::endl;
	
	const Animal* animal = new Animal();
	Dog* luli = new Dog();
	Cat* naza = new Cat();

	luli->setIdeaDog(0, "Soy Luli el perro");
	naza->setIdeaCat(0, "Soy Naza el gato");
	naza->setIdeaCat(-3, "Soy Naza el gato");
		
	std::cout << BOLD << BRIGHT_MAGENTA << "------ tipo e ideas ------" << RESET << std::endl;
	std::cout << "tipo naza: " << naza->getType() << std::endl;
	std::cout << "tipo luli: " << luli->getType() << std::endl;
	std::cout << "tipo animal: " << animal->getType() << std::endl;

	std::cout << "idea naza: " << naza->getIdeaCat(0) << std::endl;
	std::cout << "idea naza: " << naza->getIdeaCat(2) << std::endl;
	std::cout << "idea luli: " << luli->getIdeaDog(0) << std::endl;
	std::cout << "idea luli: " << luli->getIdeaDog(-3) << std::endl;
		
	std::cout << BOLD << BRIGHT_MAGENTA << "------ cerebro ------" << RESET << std::endl;

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
	
	std::cout << BOLD << BRIGHT_MAGENTA << "------ destructor ------" << RESET << std::endl;
	delete naza;
	delete luli;
	delete animal;

	std::cout << BOLD << BRIGHT_MAGENTA << "------ Prueba Array (Requisito del Subject) ------" << RESET << std::endl;
	const int N = 4;
	Animal* animals[N];

	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
		{
			Dog* d = new Dog();
			d->setIdeaDog(0, "Soy un perro");
			animals[i] = d;
		}
		else
		{
			Cat* c = new Cat();
			c->setIdeaCat(0, "Soy un gato");
			animals[i] = c;
		}
	}

	std::cout << " -----> Borrando array..." << std::endl;
	for (int i = 0; i < N; i++)
	{
		delete animals[i];
	}

	return (0);
}