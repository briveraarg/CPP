/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:17:22 by brivera           #+#    #+#             */
/*   Updated: 2026/01/14 15:10:31 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "utils.hpp"

#define RESET			"\033[0m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_GREEN	"\033[92m"

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << BRIGHT_BLUE << "\n=== TEST 1.0: Array de INT ===" << RESET << std::endl;
	std::cout << "Original: ";
	iter(arr, len, print<int>);
	std::cout << std::endl;

	std::cout << "Incrementando (+1)..." << std::endl;
	iter(arr, len, increment<int>);
	
	std::cout << "Modificado: ";
	iter(arr, len, print<int>);

	std::cout << BRIGHT_GREEN << "\n\n=== TEST 1.1: Functor (PrintLessThan 4) ===" << RESET << std::endl;
	std::cout << "Valores menores que 4 en el array modificado:" << std::endl;
	iter(arr, len, PrintLessThan<int>(6));
	
	std::cout << BRIGHT_MAGENTA << "\n=== TEST 2.0: Array de STRING ===" << RESET << std::endl;
	std::string strArr[] = {"Argentina", "campeon", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);
	std::cout << "Original: ";
	iter(strArr, strLen, print<std::string>);
	
	std::cout << "Añadiendo sufijo '***'..." << std::endl;
	iter(strArr, strLen, AddSuffix("***"));
	
	std::cout << "Modificado: ";
	iter(strArr, strLen, print<std::string>);
	return (0);
}

