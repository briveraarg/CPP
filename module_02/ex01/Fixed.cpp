/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:40:44 by brivera           #+#    #+#             */
/*   Updated: 2025/10/27 16:30:58 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed (const int	nbr): _value(nbr * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float nbr) : _value(static_cast<int>((nbr * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const 
{
	return(static_cast<int>(this->toFloat()));
}

float Fixed::toFloat(void) const
{
	
	return(static_cast<float>(_value)/ static_cast<float>(1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& a, const Fixed& fixed)
{
	a << fixed.toFloat();
	return (a);
}
