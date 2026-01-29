/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:23:32 by brivera           #+#    #+#             */
/*   Updated: 2026/01/29 13:23:38 by brivera          ###   ########.fr       */
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
#include <ctime>

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

/***** métodos públicos *****/

void	BitcoinExchange::loadDataBase(const std::string& file)
{
	std::ifstream	FileDataBase(file.c_str());
	std::string		line;
	std::string		date;
	std::string		value;
	float			num;

	if (!FileDataBase.is_open())
		throw std::runtime_error("Error: could not open database file.");
	std::getline(FileDataBase, line);
	while (std::getline(FileDataBase, line))
	{
		if (line.empty())
			continue;
		errno = 0;
		std::stringstream ss(line);
		if (!std::getline(ss, date, ','))
			throw std::runtime_error("Error: invalid format in database.");
		if (!_isValidDate(date))
			throw std::runtime_error("Error: invalid date in database ==> " + date);
		if (!std::getline(ss, value))
			throw std::runtime_error("Error: invalid format in database.");
		try{
			num = _stringToFloat(value);
		}
		catch (std::exception &e){
			throw std::runtime_error("Error: bad float value in database => " + line);
		}
		_dataBase.insert(std::make_pair(date, num));
	}
	FileDataBase.close();
}

void	BitcoinExchange::processInput(const std::string& file) const
{
	std::ifstream	fileInput(file.c_str());
	std::string		line;

	if(!fileInput.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::getline(fileInput, line);
	while (std::getline(fileInput, line))
	{
		if (line.empty())
			continue;

		size_t delim = line.find(" | ");
		if (delim == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, delim);
		std::string valStr = line.substr(delim + 3);
		if (!_isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		float val;
		try
		{
			val = _stringToFloat(valStr);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (val < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		//std::map<std::string, float>::const_iterator it;
		//for (it = _dataBase.begin(); it != _dataBase.end(); ++it){
		//	std::cout << date << " => " << valStr << " = " << it->second << std::endl;

		std::map<std::string, float>::const_iterator it;
		it = _dataBase.lower_bound(date);
		if (it != _dataBase.end() && it->first == date)
   			std::cout << it->first << " => " << val << " = " << val * it->second << std::endl;
		else
		{
        	--it;
        	std::cout << it->first << " => " << val << " = " << val * it->second << std::endl;
   		}
	}
	fileInput.close();
}

/***** métodos privados *****/

float	BitcoinExchange::_stringToFloat(const std::string& str) const
{
	float	num;
	char*	end = NULL;

	errno = 0;
	num = std::strtof(str.c_str(), &end);
	if (end == str.c_str() || errno == ERANGE || *end != '\0')
		throw std::exception();
	return (num);
}

bool	BitcoinExchange::_isValidDate(const std::string& date) const
{
	struct tm tm;
	std::memset(&tm, 0, sizeof(struct tm)); // IMPORTANT: Initialize tm struct

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);
	if (date.length() != 10)
		return (false);
	
	int d = tm.tm_mday;
	int m = tm.tm_mon;
	int y = tm.tm_year;
	
	if (mktime(&tm) == -1 || tm.tm_mday != d || tm.tm_mon != m || tm.tm_year != y)
		return (false);
	return (true);
}
