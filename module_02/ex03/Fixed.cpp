/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:15:45 by brivera           #+#    #+#             */
/*   Updated: 2025/11/04 12:59:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Implementación de Fixed 
// - Los constructores inicializan el valor interno _value.
// - toFloat() y toInt() permiten convertir entre la representación
//   interna y tipos de C++.
// - Operaciones aritméticas usan la representación raw y ajustan
//   por _fractionalBits para mantener precisión.

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
}

Fixed::Fixed (const int    nbr): _value(nbr * (1 << _fractionalBits))
{
}

Fixed::Fixed (const float nbr) : _value(static_cast<int>(roundf(nbr * (1 << _fractionalBits))))
{
}


Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const 
{
	return (static_cast<int>(this->toFloat()));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value)/ static_cast<float>(1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& a, const Fixed& fixed)
{
	a << fixed.toFloat();
	return (a);
}

/* ------------------------- Implementación operadores ------------------------- */

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->_value + other._value);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->_value - other._value);
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed    res;
	long long mul;

	mul = static_cast<long long>(this->_value) * static_cast<long long>(other._value);
	res.setRawBits(static_cast<int>(mul >> _fractionalBits));
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed        res;
	long long    num;

	num = (static_cast<long long>(this->_value) << _fractionalBits);
	res.setRawBits(static_cast<int>(num / static_cast<long long>(other._value)));
	return (res);
}

Fixed& Fixed::operator++()
{
	++(this->_value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed    tmp(*this);

	++(*this);
	return (tmp);
}

Fixed& Fixed::operator--()
{
	--(this->_value);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed    tmp(*this);

	--(*this);
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}
