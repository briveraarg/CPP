/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:23:32 by brivera           #+#    #+#             */
/*   Updated: 2026/01/27 17:23:32 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <cstring>
#include <sstream>
#include <map>

/***** constructores y destructor *****/
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_dataBase = other._dataBase;
}
BitcoinExchange::~BitcoinExchange()
{
}

/***** operador *****/

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_dataBase = other._dataBase;
	return (*this);
}

/***** métodos *****/

void	BitcoinExchange::loadDataBase(const std::string& file)
{
	std::ifstream	FileDataBase(file.c_str());
	std::string		line;

	if (!FileDataBase.is_open())
		throw std::runtime_error("Can't open file: " + file);
	std::getline(FileDataBase, line);
	while (std::getline(FileDataBase, line))
	{
		std::string		date;
		double			value;
		
		std::stringstream ss(line);
		if (!std::getline(ss, date, ','))
			return ;
		if (!ss || !(ss >> value))
			throw std::runtime_error(file + ": bad data base");
		std::cout << date << std::endl;
		std::cout << value << std::endl;
		_dataBase.insert(std::make_pair(date, value));
	}
	FileDataBase.close();
}
