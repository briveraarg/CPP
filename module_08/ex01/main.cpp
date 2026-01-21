/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:04 by brivera           #+#    #+#             */
/*   Updated: 2026/01/21 16:58:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>

int main()
{
	Span	miVector(5);

	try
	{
		miVector.addNumber(7);
		miVector.addNumber(0);
		miVector.addNumber(1);
		miVector.addNumber(2);
		miVector.addNumber(3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << miVector[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << miVector.shortestSpan() << std::endl;
	return (0);
}