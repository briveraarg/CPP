/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:45:43 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 17:15:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Use: ./RPN  \"2 2 +\"" << std::endl, 1);
	RPN		stack;
	try{
		std::cout << stack.calculator(argv[1]) << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << BRIGHT_RED << e.what() << '\n' << RESET;}
	return (0);
}