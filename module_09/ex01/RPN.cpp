/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:03 by brivera           #+#    #+#             */
/*   Updated: 2026/01/30 14:10:22 by brivera          ###   ########.fr       */
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

/* ========= operador ========= */

RPN& RPN::operator=(const RPN& other)
{
	(void) other;
	return (*this);
}

/* ========= metodos ========= */

int RPN::calculator(const std::string& input)
{
	int	res = 0;
	int	num1 = 0;
	int num2 = 0;

	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (!isdigit(static_cast<int>(c)) &&
			c != '+' && c != '-' && c!= '*' && c != '/'
			&& !isspace(static_cast<int>(c)))
			throw std::runtime_error("Error cositas nada que ver");
		if (isdigit(static_cast<int>(c)))
		{
			num1 = c - '0';
			_pilaNumber.push(num1);
			if (i < input.length())
				i++;
			c = input[i];
			if (isspace(static_cast<int>(c)))
				continue ;
			else
				throw std::runtime_error("Error de sintaxis1");
		}
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_pilaNumber.size() < 2)
				throw std::runtime_error("Error de sintaxis2");
			num2 = _pilaNumber.top();
			_pilaNumber.pop();
			num1 = _pilaNumber.top();
			_pilaNumber.pop();
			//std::cout << "n1 => " << num1 << std::endl;
			//std::cout << "n2 => " << num2 << std::endl;
			switch (c)
			{
				case '+':
					res = num1 + num2;
					break;
				case '-':
					res = num1 - num2;
					break;
				case '*':
					res = num1 * num2;
					break;
				default:
					res = num1 / num2;
					break;
			}
			_pilaNumber.push(res);
		}
		//std::cout << res << std::endl;
	}
	if (_pilaNumber.size() != 1)
				throw std::runtime_error("Error quedaron cositas");
	return (res);
}

