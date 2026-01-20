/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:42:59 by brivera           #+#    #+#             */
/*   Updated: 2026/01/20 14:44:08 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

#define RESET			"\033[0m"
#define BRIGHT_GREEN	"\033[92m"

#define MAX_NUM 300

int main()
{
	
	//std::cout 
	std::vector<int>	v;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % 100;
		v.push_back(value);
	}
	try
	{
		std::cout << *easyfind(v, 15) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	return (0);
}
