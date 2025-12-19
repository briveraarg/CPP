/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:04:43 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 16:37:45 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// std::cout, std::cerr, std::endl
#include <cstdlib>	// std::strtod, std::strtol
#include <cerrno>	// errno, ERANGE
#include <cctype>	// std::isdigit
#include <climits>	// INT_MIN, INT_MAX

/* ---- constructores y destructores ---- */

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

/* ----  Operador de asignación ---- */

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

/* ---- métodos ---- */

// Comprueba si hay un '.' en el rango [start, end)
static bool	has_dot_in_range(const char *start, const char *end)
{
	bool	before_digit = false;
	bool	after_digit = false;
	
	for (const char *p = start; p < end; ++p)
	{
		if (*p == '.')
		{
			before_digit = (p > start)
				&& std::isdigit(static_cast<unsigned char>(*(p - 1)));
			after_digit = (p + 1 < end)
				&& std::isdigit(static_cast<unsigned char>(*(p + 1)));
			return (before_digit && after_digit); 
		}
	}
	return (false);
}

bool	ScalarConverter::isChar(const std::string& argument)
{
	char	c;

	if (argument.size() == 3 && argument[0] == '\'' && argument[2] == '\'' )
	{
		c = argument[1];
		if (c >= 32 && c <= 126)
			return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt(const std::string& argument)
{
	const char *cstr = argument.c_str();
	char *endptr = NULL;

	errno = 0;
	long n = std::strtol(cstr, &endptr, 10);

	if (endptr == cstr)
		return (false);
	if (*endptr != '\0')
		return (false);
	if (errno == ERANGE)
		return (false);
	if (n < INT_MIN || n > INT_MAX)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;

	errno = 0;
	double n = std::strtod(cstr, &endptr);

	if (endptr == cstr)
		return (false);
	if (errno == ERANGE)
		return (false);
	if (*endptr != 'f' || endptr[1] != '\0')
		return (false);
	if (!has_dot_in_range(cstr, endptr))
		return (false);

	(void)n;
	return true;
}

bool	ScalarConverter::isDouble(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;

	errno = 0;
	double n = std::strtod(cstr, &endptr);
	if (endptr == cstr)
		return (false);
	if (errno == ERANGE)
		return (false);
	if (*endptr != '\0')
		return (false);
	if (!has_dot_in_range(cstr, endptr))
		return (false);
	(void)n;
	return (true);
}

void	ScalarConverter::convert(const std::string& argument)
{
	if (isChar(argument))
	{
		std::cout << "char: " << argument << std::endl;
		return ;
	}
	if (isInt(argument))
	{
		std::cout << "int: " << argument << std::endl;
		return ;
	}
	if (isFloat(argument))
	{
		std::cout << "float : " << argument << std::endl;
		return ;
	}
	if (isDouble(argument))
	{
		std::cout << "double : " << argument << std::endl;
		return ;
	}
	std::cout << "no es nada" << std::endl;
}

