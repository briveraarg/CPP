/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:27:04 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 12:44:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed d( b );
	a = Fixed( 1234.4321f );
	d.setRawBits(256);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	/* ------------------------------------------------------------------ */
	/*  Pruebas rápidas: truncamiento vs roundf y comportamiento con negativos */
	/* ------------------------------------------------------------------ */

	float nbr = 42.42f;
	int scaled = static_cast<int>(nbr * (1 << 8)); // truncamiento directo
	int rounded = static_cast<int>(roundf(nbr * (1 << 8)));

	Fixed fromFloat(nbr);               // usa roundf dentro del constructor
	Fixed truncFixed; truncFixed.setRawBits(scaled); // simulamos conversión por truncamiento
	Fixed roundFixed; roundFixed.setRawBits(rounded); // simulamos conversión por roundf

	std::cout << std::endl << "--- Comparación (positivo) ---" << std::endl;
	std::cout << "valor original float: " << nbr << std::endl;
	std::cout << "scaled (nbr * 256) truncated raw: " << scaled << std::endl;
	std::cout << "scaled (nbr * 256) rounded raw:   " << rounded << std::endl;
	std::cout << "fromFloat (constructor): " << fromFloat << "  toInt()=" << fromFloat.toInt() << "  (int)toFloat=" << static_cast<int>(fromFloat.toFloat()) << std::endl;
	std::cout << "truncFixed (setRawBits trunc): " << truncFixed << "  toInt()=" << truncFixed.toInt() << "  (int)toFloat=" << static_cast<int>(truncFixed.toFloat()) << std::endl;
	std::cout << "roundFixed (setRawBits round):  " << roundFixed << "  toInt()=" << roundFixed.toInt() << "  (int)toFloat=" << static_cast<int>(roundFixed.toFloat()) << std::endl;

	/* Prueba con número negativo */
	float nbrN = -42.42f;
	int scaledN = static_cast<int>(nbrN * (1 << 8)); // truncamiento directo
	int roundedN = static_cast<int>(roundf(nbrN * (1 << 8)));

	Fixed fromFloatN(nbrN);
	Fixed truncFixedN; truncFixedN.setRawBits(scaledN);
	Fixed roundFixedN; roundFixedN.setRawBits(roundedN);

	std::cout << std::endl << "--- Comparación (negativo) ---" << std::endl;
	std::cout << "valor original float: " << nbrN << std::endl;
	std::cout << "scaled (nbr * 256) truncated raw: " << scaledN << std::endl;
	std::cout << "scaled (nbr * 256) rounded raw:   " << roundedN << std::endl;
	std::cout << "fromFloat (constructor): " << fromFloatN << "  toInt()=" << fromFloatN.toInt() << "  (int)toFloat=" << static_cast<int>(fromFloatN.toFloat()) << std::endl;
	std::cout << "truncFixed (setRawBits trunc): " << truncFixedN << "  toInt()=" << truncFixedN.toInt() << "  (int)toFloat=" << static_cast<int>(truncFixedN.toFloat()) << std::endl;
	std::cout << "roundFixed (setRawBits round):  " << roundFixedN << "  toInt()=" << roundFixedN.toInt() << "  (int)toFloat=" << static_cast<int>(roundFixedN.toFloat()) << std::endl;
	return 0;
}
