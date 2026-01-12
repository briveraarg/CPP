/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:26:46 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 14:41:51 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "color.hpp"

Base * generate(void)
{
	int r = std::rand() % 3;

	if (r == 0)
		return (new A());
	else if (r == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown" << std::endl;
}

/*
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Garantiza que las pruebas sean realmente aleatorias en cada ejecución.
*/

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << BRIGHT_BLUE << "--- Identificación por puntero ---" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Base* ptr = generate();
		std::cout << "Objeto generado " << i + 1 << ": ";
		identify(ptr);
		delete ptr;
	}

	std::cout << BRIGHT_BLUE << "\n--- Identificación por referencia ---" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Base* ptr = generate();
		std::cout << "Objeto generado " << i + 1 << ": ";
		identify(*ptr);
		delete ptr;
	}
	std::cout << BRIGHT_BLUE << "\n--- Caso de Unknown ---" << RESET << std::endl;
	Base p = A();
	identify(&p);
	return (0);
}
