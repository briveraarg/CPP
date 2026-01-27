/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:22:02 by brivera           #+#    #+#             */
/*   Updated: 2026/01/27 13:41:51 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Use: ./btc file" << std::endl, 1);
	BitcoinExchange	btc;
	try
	{
		btc.loadDataBase("data.csv");
		argv[1] = NULL;
		//btc.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
