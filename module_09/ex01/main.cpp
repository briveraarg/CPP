/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:45:43 by brivera           #+#    #+#             */
/*   Updated: 2026/01/29 19:07:11 by brivera          ###   ########.fr       */
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
		stack.calculator(argv[1]);}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';}
	return (0);
}