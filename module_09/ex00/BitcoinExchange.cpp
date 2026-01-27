/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:23:32 by brivera           #+#    #+#             */
/*   Updated: 2026/01/27 18:28:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <exception>
#include <cstring>
#include <sstream>
#include <cstdlib>
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


void	BitcoinExchange::loadDataBase(const std::string& file)
{
	std::ifstream	FileDataBase(file.c_str());
	std::string		line;

	if (!FileDataBase.is_open())
		throw std::runtime_error("Can't open file: " + file);
	
	std::getline(FileDataBase, line);
	std::string		date;
	std::string		value;
	float			num;
	char*			end = NULL;
	while (std::getline(FileDataBase, line))
	{
		
		errno = 0;
		std::stringstream ss(line);
		if (!std::getline(ss, date, ','))
			throw std::logic_error(file + ": error getline");
		if (!std::getline(ss, value, ' '))
			throw std::logic_error(file + ": error getline");
		num = std::strtof(value.c_str(), &end);
		if (end == value || errno == ERANGE || *end != '\0')
			throw std::runtime_error(file + ": bad data base. \nLine: " + line);
		// if (!ss || !(ss >> value) || !ss.eof())
		// 	throw std::runtime_error(file + ": bad data base");
		_dataBase.insert(std::make_pair(date, num));
	}
	FileDataBase.close();
}
