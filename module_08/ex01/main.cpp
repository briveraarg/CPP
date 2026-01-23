/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:04 by brivera           #+#    #+#             */
/*   Updated: 2026/01/23 14:57:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <ctime>

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_BLUE		"\033[94m"
#define BOLD			"\033[1m"

int main()
{
	std::cout << BRIGHT_BLUE BOLD
		<< "=== TEST BÁSICO ===" << RESET << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	} catch(const std::exception& e){
		std::cerr << BRIGHT_RED << e.what() << '\n' << RESET;
	}
	
	std::cout << BRIGHT_BLUE BOLD
		<< "\n=== TEST GRANDE (10,000 números) ==="
			<< RESET << std::endl;
	try
	{
		std::vector<int> bigVector(10000);
		std::srand(std::time(NULL));
		std::generate(bigVector.begin(), bigVector.end(), std::rand);

		Span sp(10000);
		sp.addNumber(bigVector.begin(), bigVector.end());

		std::cout << "Shortest span (10k): "
			<< sp.shortestSpan() << std::endl;
		std::cout << "Longest span (10k): "
			<< sp.longestSpan() << std::endl;
	} catch (std::exception &e){
		std::cerr << BRIGHT_RED << e.what() << RESET << std::endl;
	}
	
	std::cout << BRIGHT_BLUE BOLD
		<< "\n=== TEST EXCEPCIONES ===" << RESET << std::endl;
	try
	{
		Span sp(5);
		sp.shortestSpan();
	} catch (std::exception &e){
		std::cout << "Empty span exception: "
			<< BRIGHT_RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	} catch (std::exception &e){
		std::cout << "Full span exception: "
			<< BRIGHT_RED << e.what() << RESET << std::endl;
	}

	try 
	{
		Span sp(5);
		sp.addNumber(1);
		std::cout << sp[10] << std::endl;
	} catch (std::exception &e){
		std::cout << "Index out of bounds exception: "
			<< BRIGHT_RED << e.what() << RESET << std::endl;
	}

	std::cout << BRIGHT_BLUE BOLD
		<< "\n=== TEST COPIA Y ASIGNACIÓN ===" << RESET << std::endl;
	try
	{
		Span original(3);
		original.addNumber(10);
		original.addNumber(20);
		original.addNumber(30);

		Span copy(original);
		Span assigned(1);
		assigned = original;

		std::cout << "Copy shortest: "
			<< copy.shortestSpan() << std::endl;
		std::cout << "Assigned longest: "
			<< assigned.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
