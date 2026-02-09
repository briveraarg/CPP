/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:03 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 18:58:52 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
	if (input.empty())
		throw std::runtime_error("Error");
	if (isspace(input[0]) || isspace(input[input.length() - 1]))
		throw std::runtime_error("Error");

	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (isdigit(c) && i + 1 < input.length() && isspace(input[i + 1]))
		{
			if (i + 1 < input.length() && isdigit(input[i + 1]))
				throw std::runtime_error("Error");
			_pilaNumber.push(c - '0');
		}
		else if (_isOperator(c))
		{
			if (input[i + 1] != '\0' && !isspace(input[i + 1]))
				throw std::runtime_error("Error");
			_performOperation(c);
		}
		else if (isspace(c))
			continue;
		else
			throw std::runtime_error("Error");
	}
	if (_pilaNumber.size() != 1)
		throw std::runtime_error("Error");
	return (_pilaNumber.top());
}

bool RPN::_isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::_performOperation(char op)
{
	if (_pilaNumber.size() < 2)
		throw std::runtime_error("Error");
	int num2 = _pilaNumber.top();
	_pilaNumber.pop();
	int num1 = _pilaNumber.top();
	_pilaNumber.pop();
	long long tempRes = 0;
	switch (op)
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
		case '/':
			if (num2 == 0)
				throw std::runtime_error("Error");
			tempRes = static_cast<long long>(num1) / num2;
			break;
	}
	if (tempRes > INT_MAX || tempRes < INT_MIN)
		throw std::runtime_error("Error");
	_pilaNumber.push(static_cast<int>(tempRes));
}
