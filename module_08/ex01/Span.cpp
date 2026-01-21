/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:51 by brivera           #+#    #+#             */
/*   Updated: 2026/01/21 14:45:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define BOLD			"\033[1m"
#define RESET			"\033[0m"

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Spam" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

/***** constructores y destructores *******/

Span::Span(void): _size(0)
{
	DBG_MSG("default constructor called");
}

Span::Span(unsigned int N): _size(N)
{
	DBG_MSG("parameterized constructor called");
}

Span::Span(const Span& other): _size(other._size), _v(other._v)
{
	DBG_MSG("copy constructor called");
}
Span::~Span()
{
	DBG_MSG("destructor called");
}

/***** operador *******/

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_size = other._size;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_v[i] = other[i];
	}
	DBG_MSG("assignment operator called");
	return(*this);
}

int Span::operator[](unsigned int index) const
{
	if(index >= this->_size)
		throw Span::limitSizeExeption();
	return (this->_v[index]);
}

const char* Span::limitSizeExeption::what() const throw()
{
	return ("Spam::fuera de rango");
}
/***** metodos *******/

void	Span::addNumber(int num)
{
	this->_v.push_back(num);
}
