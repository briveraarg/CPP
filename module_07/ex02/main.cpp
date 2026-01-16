/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:19:18 by brivera           #+#    #+#             */
/*   Updated: 2026/01/14 15:57:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"
#include "color.hpp"

#define MAX_VAL 5

int main(int, char**)
{
	std::cout << BOLD << BRIGHT_GREEN << "=== TEST 1: Construcción y Llenado ===" << RESET << std::endl;
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout << "[" << i << "] " << value << std::endl;
	}

	//SCOPE
	std::cout << BOLD << BRIGHT_CYAN << "\n=== TEST 2: Copia Profunda ==="
				<< RESET << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		std::cout << "Array temp -> ";
		std::cout << "[" << MAX_VAL - 1 << "]" << tmp[MAX_VAL-1] << std::endl;
		std::cout << "Array test -> ";
		std::cout << "[" << MAX_VAL - 1 << "]" << test[MAX_VAL-1] << std::endl;
	}
	
	std::cout << BOLD << BRIGHT_MAGENTA << "\n=== TEST 3: Verificación de copias ==="
				<< RESET << std::endl;
	std::cout << "Mirror" << "\t\t" << "Numbers\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << BRIGHT_RED << "Error: ¡diferente valor!" << RESET << std::endl;
			return (1);
		}
		std::cout << "[" << i << "] " << mirror[i] << "\t";
		std::cout << "[" << i << "] " << numbers[i] << std::endl;
	}
	
	std::cout << BOLD << BRIGHT_BLUE << "\n=== TEST 4: Excepciones ===" << RESET << std::endl;
	std::cout << BOLD << "Probando índice -2:" << RESET << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << RESET << e.what()
			<< std::endl;
	}

	std::cout << BOLD << "\nProbando índice MAX_VAL:" << RESET << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: " << RESET << e.what()
			<< std::endl;
	}
	
	std::cout << BOLD << "\nProbando índice válido MAX_VAL / 2:" << RESET << std::endl;
	try
	{
		std::cout << "Valor antes en numbers: " << "[" << (MAX_VAL / 2) << "] " 
		<< numbers[MAX_VAL / 2] << std::endl;
		numbers[MAX_VAL / 2] = 0;
		std::cout << "Valor despues en numbers: " << "[" << (MAX_VAL / 2) << "] " 
		<< numbers[MAX_VAL / 2] << std::endl;
		std::cout << "Valor en mirror: " << "[" << (MAX_VAL / 2) << "] " 
		<< mirror[MAX_VAL / 2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BRIGHT_RED << "Excepción capturada: "<< RESET << e.what()
			<< std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	delete [] mirror;
	return (0);
}