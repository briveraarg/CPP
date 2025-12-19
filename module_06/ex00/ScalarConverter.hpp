/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:59:01 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 12:36:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <limits.h>
#include <cstdlib>
#include <cerrno>

enum Format
{
	CHAR=1,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool	isChar(const std::string& argument);
		static bool isInt(const std::string& argument);
		static bool isFloat(const std::string& argument);
		static bool isDouble(const std::string& argument);
	public:
		static void convert(const std::string& argument);

};

#endif