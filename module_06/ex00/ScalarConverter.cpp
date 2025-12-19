/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:04:43 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 19:55:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// std::cout, std::cerr, std::endl
#include <cstdlib>	// std::strtod, std::strtol
#include <cerrno>	// errno, ERANGE
#include <cctype>	// std::isdigit
#include <climits>	// INT_MIN, INT_MAX
#include <stddef.h>
#include "ScalarPrinter.hpp"

/* ---- ScalarPrinter.cpp/.hpp helper functions ---- */

static void printCharLiteral(const std::string& argument)
{
	char c = argument[1];
	double val = static_cast<double>(static_cast<unsigned char>(c));
	output_char_from_double(val);
	output_int_from_double(val);
	output_float_from_double(val);
	output_double_from_double(val);
}

static void printIntLiteral(const std::string& argument)
{
	int value = std::atoi(argument.c_str());
	double val = static_cast<double>(value);
	output_char_from_double(val);
	output_int_from_double(val);
	output_float_from_double(val);
	output_double_from_double(val);
}

static void printFloatLiteral(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;
	errno = 0;
	double value = std::strtod(cstr, &endptr);
	output_char_from_double(value);
	output_int_from_double(value);
	output_float_from_double(value);
	output_double_from_double(value);
}

static void printDoubleLiteral(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;
	errno = 0;
	double value = std::strtod(cstr, &endptr);
	output_char_from_double(value);
	output_int_from_double(value);
	output_float_from_double(value);
	output_double_from_double(value);
}

/* ---- helper function: check if there is a decimal point ---- */

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

/* ---- constructors and destructor ---- */

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

/* ---- Assignment operator ---- */

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

/* ---- methods to check which type the argument is ---- */


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

/* ---- main function ---- */

void	ScalarConverter::convert(const std::string& argument)
{
	struct Entry { bool (*is)(const std::string&); void (*print)(const std::string&); };

	static Entry table[] =
	{
		{ &ScalarConverter::isChar,  &printCharLiteral },
		{ &ScalarConverter::isInt,   &printIntLiteral  },
		{ &ScalarConverter::isFloat, &printFloatLiteral},
		{ &ScalarConverter::isDouble,&printDoubleLiteral}
	};

	for (size_t i = 0; i < sizeof(table)/sizeof(table[0]); ++i)
	{
		if (table[i].is(argument))
		{
			table[i].print(argument);
			return;
		}
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

