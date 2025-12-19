/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:04:43 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 12:39:43 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib> // strtod/strtol
#include <cerrno>
#include <cstring>

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

	// No se parseó ningún dígito válido
	if (endptr == cstr)
		return (false);
	// Si quedan caracteres no convertidos
	if (*endptr != '\0')
		return (false);
	// Comprueba errores de rango
	if (errno == ERANGE)
		return (false);
	//entra en un INT
	if (n < INT_MIN || n > INT_MAX)
		return (false);
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& argument)
{
	const char* cstr = argument.c_str();
	char* endptr = NULL;

	errno = 0;
	double v = std::strtod(cstr, &endptr);

	if (endptr == cstr)
		return (false);
	if (errno == ERANGE)
		return (false);
	if (*endptr != 'f' || endptr[1] != '\0')
		return (false);
	(void)v; 
	return (true);
}

bool	ScalarConverter::isDouble(const std::string& argument)
{
	
}

void	ScalarConverter::convert(const std::string& argument)
{
	int	type = 0;

	if (isChar(argument))
	{
		type = CHAR;
		std::cout << "char: " << argument << std::endl;
	}
	if (isInt(argument))
	{
		std::cout << "int: " << argument << std::endl;
	}
	if (isFloat(argument))
	{
		std::cout << "float : " << argument << std::endl;
	}

}

/*
	double valor = 0;

	if (type == CHAR)
	{
		char	c = argument[0];
		int		ascii = static_cast<int>(static_cast<unsigned char>(c));

		valor = ascii;
		std::cout << "double: " << valor << std::endl;
		return ;
	}

	char *endptr = NULL;
	errno = 0;
	const char *cstr = argument.c_str();
	
	valor = std::strtod(cstr, &endptr);

	if (endptr == cstr)
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (errno == ERANGE)
	{
		// Desbordamiento o underflow;
	}
	if (*endptr != '\0')
	{
		if (!(endptr[0] == 'f' && endptr[1] == '\0'))
		{
			// Hay caracteres inválidos después del número -> tratar como error
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	std::cout << "double: " << valor << std::endl;
*/