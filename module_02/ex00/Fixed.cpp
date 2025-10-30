/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:20:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 16:20:10 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 
 * Definición del miembro estático (C++98): cantidad de bits fraccionales
*/

const int Fixed::_fractionalBits = 8;

/*
 * Constructor por defecto: inicializa el valor raw a 0
*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Constructor de copia: copia el valor raw del objeto origen
*/

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
 * Operador de asignación por copia: protege auto-asignación y copia el raw
*/

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other._value;
	}
	return (*this);
}

/*
 * Destructor: no reserva de memoria dinamica, solo sacamos el mensaje
 * que nos pide el subjet. 
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Devuelve el valor bruto almacenado e imprime trazas de depuración
 *
*/

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

