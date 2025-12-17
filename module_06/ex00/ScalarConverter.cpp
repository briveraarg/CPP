/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:04:43 by brivera           #+#    #+#             */
/*   Updated: 2025/12/17 19:30:15 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

/* ---- método ---- */

// Comprobaciones (C++98):
// - endptr == cstr -> no se parseó ningún dígito válido
// - ERANGE        -> overflow/underflow
// - *endptr != '\0' -> quedan caracteres no convertidos

void	ScalarConverter::convert(const std::string& argument)
{
	double valor = 0;

	if (argument.size() == 1)
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
}