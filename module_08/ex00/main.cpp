/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:59 by brivera           #+#    #+#             */
/*   Updated: 2026/01/22 12:44:58 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

#define RESET			"\033[0m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_BLUE		"\033[94m"
#define BOLD			"\033[1m"

#define MAX_NUM 6
#define NUM1	5
#define NUM2	2

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << BRIGHT_BLUE BOLD << "=== TEST 1: VECTOR ===" << RESET << std::endl;
	std::vector<int>	v;
	std::cout  << BOLD << "Generando valores..." << RESET << std::endl;
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % 10;
		v.push_back(value);
		std::cout << "[" << i << "] " << v[i] << std::endl;
	}
	
	std::cout  << BOLD << "Buscando el valor: " << RESET << NUM1 << std::endl; 
	try{
		std::cout << BOLD << "Encontrado: " << *easyfind(v, NUM1) << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cerr << BRIGHT_RED << "\n" << e.what() << RESET << std::endl;
	}

	std::cout << BRIGHT_BLUE BOLD << "\n=== TEST 2: LISTA ===" << RESET << std::endl;
	std::list<int>	l;
	std::cout  << BOLD << "Generando valores..." << RESET << std::endl;
	
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % 10;
		l.push_back(value);
		std::cout << "-> " << value << std::endl;
	}
	
	std::cout << BOLD << "Buscando el valor: " << RESET << NUM2 << std::endl;
	try{
		std::cout << BOLD << "Encontrado: " << *easyfind(l, NUM2) << RESET << std::endl;
	}
	catch (std::exception & e){
		std::cerr << BRIGHT_RED << "\n" << e.what() << RESET << std::endl;
	}
	
	return (0);
}
