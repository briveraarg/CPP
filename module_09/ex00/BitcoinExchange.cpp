/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:23:32 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 17:11:26 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ======= constructores =======*/
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_dataBase = other._dataBase;
}

/* ======= destructor =======*/

BitcoinExchange::~BitcoinExchange()
{
}

/* ======= operador =======*/


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_dataBase = other._dataBase;
	return (*this);
}

/* ======= métodos públicos =======*/


void	BitcoinExchange::loadDataBase(const std::string& file)
{
	std::ifstream	FileDataBase(file.c_str());
	std::string		line;
	std::string		date;
	std::string		value;
	float			num;

	if (!FileDataBase.is_open())
		throw std::runtime_error(BRIGHT_RED "Error: " RESET " not open database file.");
	std::getline(FileDataBase, line);
	while (std::getline(FileDataBase, line))
	{
		if (line.empty())
			continue;
		errno = 0;
		std::stringstream ss(line);
		if (!std::getline(ss, date, ','))
			throw std::runtime_error(BRIGHT_RED "Error: " RESET "invalid format in database.");
		if (!_isValidDate(date))
			throw std::runtime_error(BRIGHT_RED "Error: " RESET "invalid date in database ==> " + date);
		if (!std::getline(ss, value))
			throw std::runtime_error(BRIGHT_RED "Error: " RESET "invalid format in database.");
		try{
			num = _stringToFloat(value);
		}
		catch (std::exception &e){
			throw std::runtime_error(BRIGHT_RED "Error: " RESET "bad float value in database => " + line);
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
		throw std::runtime_error(BRIGHT_RED "Error: " RESET " not open file.");
	std::getline(fileInput, line);
	while (std::getline(fileInput, line))
	{
		if (line.empty())
			continue;
		_processLine(line);
	}
	fileInput.close();
}

float	BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it;
	it = _dataBase.lower_bound(date);
	if (it != _dataBase.end() && it->first == date)
		return (it->second);
	if (it == _dataBase.begin())
		return (0.0f); 
	--it;
	return (it->second);
}

/* ======= métodos privados =======*/

float	BitcoinExchange::_stringToFloat(const std::string& str) const
{
	float	num;
	char*	end = NULL;

	errno = 0;
	num = std::strtof(str.c_str(), &end);
	if (end == str.c_str() || errno == ERANGE)
		throw std::exception();
	while (*end)
	{
		if (!std::isspace(*end))
			throw std::exception();
		end++;
	}
	return (num);
}

/**
 * Valida si una cadena de texto representa una fecha real
 * y correctamente formateada (YYYY-MM-DD).
 * 
 * Paso a paso:
 * 1. Inicializa la estructura 'tm' a cero para evitar basura en memoria.
 * 2. strptime: Verifica que el string siga el patrón AÑO-MES-DÍA.
 * 	  Si falla el formato, retorna false.
 * 3. Longitud: Fuerza que el string tenga exactamente 10 caracteres
 * 	  (evita casos como "2023-1-1").
 * 4. Verificación de Integridad (mktime): 
 *    - mktime intenta normalizar la fecha (si le das 32 de enero,
 * 		lo convierte en 1 de febrero).
 *    - Al comparar los valores originales (d, m, y)
 * 		con los valores después de mktime, 
 *      detectamos si la fecha era inválida originalmente.
 * 
 * @param date El string de la fecha a validar.
 * @return true si la fecha existe en el calendario
 * y tiene formato correcto, false de lo contrario.
 */

bool	BitcoinExchange::_isValidDate(const std::string& date) const
{
	struct tm tm;
	memset(&tm, 0, sizeof(struct tm)); // IMPORTANT: Initialize tm struct

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);
	if (date.length() != 10)
		return (false);
	
	int d = tm.tm_mday;
	int m = tm.tm_mon;
	int y = tm.tm_year;
	
	if (mktime(&tm) == -1 ||
		tm.tm_mday != d || tm.tm_mon != m || tm.tm_year != y)
		return (false);
	return (true);
}

void	BitcoinExchange::_processLine(const std::string& line) const
{
	std::stringstream	ss(line);
	std::string			date;
	std::string			valStr;
	float				val;
	size_t				delim;

	delim = line.find(" | ");
	if (delim == std::string::npos)
	{
		std::cerr << BRIGHT_RED "Error: " RESET "bad input => " << line << std::endl;
		return;
	}
	date = line.substr(0, delim);
	valStr = line.substr(delim + 3);
	if (!_isValidDate(date))
	{
		std::cerr << BRIGHT_RED "Error: " RESET "bad input => " << date << std::endl;
		return;
	}
	try
	{
		val = _stringToFloat(valStr);
	}
	catch (std::exception &e)
	{
		std::cerr << BRIGHT_RED "Error: " RESET "bad input => " << line << std::endl;
		return;
	}
	if (val < 0)
	{
		std::cerr << BRIGHT_RED "Error: " RESET "not a positive number." << std::endl;
		return;
	}
	if (val > 1000)
	{
		std::cerr << BRIGHT_RED "Error: " RESET "too large a number." << std::endl;
		return;
	}
	std::cout << date << " => " << val << " = " << val * getExchangeRate(date) << std::endl;
}
