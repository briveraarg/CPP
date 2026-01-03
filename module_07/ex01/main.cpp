/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:17:22 by brivera           #+#    #+#             */
/*   Updated: 2026/01/03 17:54:53 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "utils.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Array INT: ";
	iter(arr, len, print<int>);
	std::cout << std::endl;

	std::cout << "Incrementing" << std::endl;
	iter(arr, len, increment<int>);

	std::cout << "Modified int array: ";
	iter(arr, len, print<int>);
	std::cout << std::endl;

	std::string strArr[] = {"Argentina", "campeon", "!"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "Array STRING: ";
	iter(strArr, strLen, print<std::string>);
	std::cout << std::endl;
	
	return (0);
}

