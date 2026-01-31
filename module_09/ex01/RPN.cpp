/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:03 by brivera           #+#    #+#             */
/*   Updated: 2026/01/31 17:58:16 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <climits>

/* ========= constructores ========= */
RPN::RPN()
{
}
RPN::RPN(const RPN& other)
{
	*this = other;
}
/* ========= destructor ========= */

RPN::~RPN()
{
}

/* ========= operador ========= */

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_pilaNumber = other._pilaNumber;
	return (*this);
}

/* ========= metodos ========= */

int RPN::calculator(const std::string& input)
{
	int		res = 0;
	int		num1 = 0;
	int		num2 = 0;

	if (input.empty())
		throw std::runtime_error("Error");
	if (isspace(input[0]) || isspace(input[input.length() - 1]))
		throw std::runtime_error("Error");
	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (isdigit(c))
		{
			if (i + 1 < input.length() && isdigit(input[i + 1]))
				throw std::runtime_error("Error");
			_pilaNumber.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_pilaNumber.size() < 2)
				throw std::runtime_error("Error");
			num2 = _pilaNumber.top();
			_pilaNumber.pop();
			num1 = _pilaNumber.top();
			_pilaNumber.pop();
			
			long long tempRes = 0;
			switch (c)
			{
				case '+':
					tempRes = static_cast<long long>(num1) + num2;
					break;
				case '-':
					tempRes = static_cast<long long>(num1) - num2;
					break;
				case '*':
					tempRes = static_cast<long long>(num1) * num2;
					break;
				default:
					if (num2 == 0)
						throw std::runtime_error("Error");
					tempRes = static_cast<long long>(num1) / num2;
					break;
			}
			if (tempRes > INT_MAX || tempRes < INT_MIN)
				throw std::runtime_error("Error");
			res = static_cast<int>(tempRes);
			_pilaNumber.push(res);
		}
		else if (c == ' ')
			continue;
		else
			throw std::runtime_error("Error");
	}
	if (_pilaNumber.size() != 1)
		throw std::runtime_error("Error");
	return (_pilaNumber.top());
}

