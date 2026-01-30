/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:03 by brivera           #+#    #+#             */
/*   Updated: 2026/01/30 18:43:56 by brivera          ###   ########.fr       */
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
	int		res = 0;
	int		num1 = 0;
	int		num2 = 0;
	bool	flag = true;

	if (input.empty())
		throw std::runtime_error("Error: empty input");
	if (isspace(input[0]) || isspace(input[input.length() - 1]))
		throw std::runtime_error("Error: sintaxis");
	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		if (isdigit(c))
		{
			if (i + 1 < input.length() && isdigit(input[i + 1]))
				throw std::runtime_error("Error: number > 10");
			_pilaNumber.push(c - '0');
			flag = true;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_pilaNumber.size() < 2)
				throw std::runtime_error("Error de sintaxis2");
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
						throw std::runtime_error("Error: division by zero");
					tempRes = static_cast<long long>(num1) / num2;
					break;
			}
			if (tempRes > INT_MAX || tempRes < INT_MIN)
				throw std::runtime_error("Error: int overflow");
			res = static_cast<int>(tempRes);
			flag = true;
			_pilaNumber.push(res);
		}
		else if ((isspace(c)) && flag)
		{
			flag = false;	
			continue;
		}
		else
			throw std::runtime_error("Error: Token invalido");
	}
	if (_pilaNumber.size() != 1)
				throw std::runtime_error("Error quedo o falto cositas");
	return (_pilaNumber.top());
}

