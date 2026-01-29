/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:03 by brivera           #+#    #+#             */
/*   Updated: 2026/01/29 19:07:41 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

/* ========= constructores ========= */
RPN::RPN()
{
}
RPN::RPN(const RPN& other)
{
	(void)other;
}
/* ========= destructor ========= */

RPN::~RPN()
{
}

/* ========= operado ========= */

RPN& RPN::operator=(const RPN& other)
{
	(void) other;
	return (*this);
}

/* ========= metodos ========= */

int RPN::calculator(const std::string& input)
{
	int	res = 0;

	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (!isdigit(static_cast<int>(c)))
			throw std::runtime_error("Error");
		std::cout << c << std::endl;
	}
	return (res);
}

