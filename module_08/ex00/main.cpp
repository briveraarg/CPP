/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:59 by brivera           #+#    #+#             */
/*   Updated: 2026/01/20 17:03:55 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <map>

#define RESET			"\033[0m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_RED		"\033[91m"
#define BOLD			"\033[1m"

#define MAX_NUM 6
#define NUM1	5
#define NUM2	2

int main()
{
	std::cout << BRIGHT_GREEN  << BOLD
		<< "*** Contenedor VECTOR ***" << RESET << std::endl;
	std::vector<int>	v;
	std::cout  << BOLD << "Buscar: " << RESET << NUM1 << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % 7;
		v.push_back(value);
		std::cout << "[" << i << "]" << v[i] << std::endl;
	}
	try
	{
		std::cout << "Easyfind: "
			<< BRIGHT_GREEN << *easyfind(v, NUM1) << RESET << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << BRIGHT_RED << e.what() << RESET << std::endl;
	}
	std::cout << "\n---------------\n" << std::endl;
	std::cout << BRIGHT_GREEN  << BOLD
		<< "*** Contenedor MAP ***" << RESET << std::endl;
	std::map<char,int>	m;
	std::cout  << BOLD << "Buscar: " << RESET << NUM2 << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	char c = 'a';
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % 7;
		m[c] = value;
		std::cout  << c << "->" << m[c] << std::endl;
		c++;
	}
	try
	{
		std::cout << "Easyfind: "
			<< BRIGHT_GREEN << *easyfind(v, NUM2) << RESET << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << BRIGHT_RED << e.what() << RESET << std::endl;
	}

	return (0);
}
