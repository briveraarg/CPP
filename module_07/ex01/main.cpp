/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:17:22 by brivera           #+#    #+#             */
/*   Updated: 2026/01/05 16:17:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "utils.hpp"

#define RESET			"\033[0m"
#define BRIGHT_MAGENTA	"\033[95m"

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << BRIGHT_MAGENTA << "\nArray de INT: " << RESET << std::endl;
	iter(arr, len, print<int>);
	iter(arr, len, increment<int>);
	
	std::cout << BRIGHT_MAGENTA << "\n\nIncrementar todos +1: "
	<< RESET << std::endl;
	iter(arr, len, print<int>);
	std::cout << std::endl;

	std::cout << BRIGHT_MAGENTA << "\nFunctor test (PrintLessThan 4):" 
	<< RESET << std::endl;
	iter(arr, len, PrintLessThan<int>(4));
	
	std::cout << BRIGHT_MAGENTA << "\n------------------\n" << RESET << std::endl;

	std::string strArr[] = {"Argentina", "campeon", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << BRIGHT_MAGENTA << "Array de STRING: " << RESET << std::endl;
	iter(strArr, strLen, print<std::string>);
	std::cout << std::endl;
	
	std::cout << BRIGHT_MAGENTA << "\nAñadir sufijo '!!!': " << RESET << std::endl;
	iter(strArr, strLen, AddSuffix("!!!"));
	iter(strArr, strLen, print<std::string>);
	std::cout << "\n" << std::endl;
	return (0);
}

