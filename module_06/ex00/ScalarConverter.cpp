/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:04:43 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 18:59:20 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// std::cout, std::cerr, std::endl
#include <cstdlib>	// std::strtod, std::strtol
#include <cerrno>	// errno, ERANGE
#include <cctype>	// std::isdigit
#include <climits>	// INT_MIN, INT_MAX
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

static bool my_isnan(double x)
{
	return (x != x);
}

static bool my_isinf(double x)
{
	using std::numeric_limits;
	if (numeric_limits<double>::has_infinity)
		return (x == numeric_limits<double>::infinity()
			|| x == -numeric_limits<double>::infinity());
	return (x > numeric_limits<double>::max() || x < -numeric_limits<double>::max());
}

static void printCharLiteral(const std::string& argument)
{
	char c = argument[1];
	int ascii = static_cast<int>(static_cast<unsigned char>(c));
	std::ostringstream od;
	od << std::fixed << std::setprecision(1) << static_cast<double>(ascii);
	std::ostringstream of;
	of << std::fixed << std::setprecision(1) << static_cast<float>(ascii);

	std::cout << "char: " << argument << std::endl;
	std::cout << "int: " << ascii << std::endl;
	std::cout << "float: " << of.str() << 'f' << std::endl;
	std::cout << "double: " << od.str() << std::endl;
}

static void printIntLiteral(const std::string& argument)
{
	int value = std::atoi(argument.c_str());
	std::ostringstream od;
	od << std::fixed << std::setprecision(1) << static_cast<double>(value);
	std::ostringstream of;
	of << std::fixed << std::setprecision(1) << static_cast<float>(value);
	if (isprint(value))
		std::cout << "char: '" << static_cast<unsigned char>(value) << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << of.str() << 'f' << std::endl;
	std::cout << "double: " << od.str() << std::endl;
}

static void printFloatLiteral(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;
	errno = 0;
	double value = std::strtod(cstr, &endptr);

	if (my_isnan(value) || my_isinf(value))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char ch = static_cast<char>(static_cast<int>(value));
		if (isprint(static_cast<unsigned char>(ch)))
			std::cout << "char: '" << ch << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// int
	if (my_isnan(value) || my_isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	float f = static_cast<float>(value);
	if (my_isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else if (my_isinf(value) || my_isinf(static_cast<double>(f)))
	{
		if (value < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}
	else
	{
		std::ostringstream of;
		of << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f;
		std::string sf = of.str();
		if (sf.find_first_of("eE.") == std::string::npos)
			sf += ".0";
		std::cout << "float: " << sf << 'f' << std::endl;
	}

	// double
	if (my_isnan(value))
	{
		std::cout << "double: nan" << std::endl;
	}
	else if (my_isinf(value))
	{
		if (value < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::ostringstream od;
		od << std::setprecision(std::numeric_limits<double>::digits10 + 1) << value;
		std::string sd = od.str();
		if (sd.find_first_of("eE.") == std::string::npos)
			sd += ".0";
		std::cout << "double: " << sd << std::endl;
	}
}

static void printDoubleLiteral(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;
	errno = 0;
	double value = std::strtod(cstr, &endptr);

	if (my_isnan(value) || my_isinf(value))
		std::cout << "char: impossible" << std::endl;
	else
	{
		char ch = static_cast<char>(static_cast<int>(value));
		if (isprint(static_cast<unsigned char>(ch)))
			std::cout << "char: '" << ch << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// int
	if (my_isnan(value) || my_isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	float f = static_cast<float>(value);
	if (my_isnan(value))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else if (my_isinf(value) || my_isinf(static_cast<double>(f)))
	{
		if (value < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}
	else
	{
		std::ostringstream of;
		of << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f;
		std::string sf = of.str();
		if (sf.find_first_of("eE.") == std::string::npos)
			sf += ".0";
		std::cout << "float: " << sf << 'f' << std::endl;
	}

	// double
	if (my_isnan(value))
	{
		std::cout << "double: nan" << std::endl;
	}
	else if (my_isinf(value))
	{
		if (value < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::ostringstream od;
		od << std::setprecision(std::numeric_limits<double>::digits10 + 1) << value;
		std::string sd = od.str();
		if (sd.find_first_of("eE.") == std::string::npos)
			sd += ".0";
		std::cout << "double: " << sd << std::endl;
	}
}
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


bool	ScalarConverter::isChar(const std::string& argument)
{
	char	c;

	if (argument.size() == 3 && argument[0] == '\'' && argument[2] == '\'' )
	{
		c = argument[1];
		if (isprint(c))
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

	if (argument == "nanf" || argument == "+inff" || argument == "-inff")
		return (true);
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
	if (argument == "nan" || argument == "+inf" || argument == "-inf")
		return (true);
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
	bool (*checkers[])(const std::string&) = {
		&ScalarConverter::isChar,
		&ScalarConverter::isInt,
		&ScalarConverter::isFloat,
		&ScalarConverter::isDouble
	};

	int matched = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (checkers[i](argument))
		{
			matched = i + 1;
			break;
		}
	}

	if (matched == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	switch (static_cast<Format>(matched))
	{
		case CHAR:
			printCharLiteral(argument);
			break;
		case INT:
			printIntLiteral(argument);
			break;
		case FLOAT:
			printFloatLiteral(argument);
			break;
		case DOUBLE:
			printDoubleLiteral(argument);
			break;
	}
}

