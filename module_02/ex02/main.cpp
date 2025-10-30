/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:19:25 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 16:51:30 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* main subjet */

/* int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
} */

int main( void )
{
	std::cout << BRIGHT_BLUE << "Demostración: resta en Fixed (raw y float)"<< RESET << std::endl;

	Fixed	a(3);
	Fixed	b(1.5f);

	std::cout << "a raw: " << a.getRawBits() << " -> a: " << a << std::endl;
	std::cout << "b raw: " << b.getRawBits() << " -> b: " << b << std::endl;

	Fixed	c = a - b;
	std::cout << std::endl << "c = a - b" << std::endl;
	std::cout << "c raw: " << c.getRawBits() << " -> c: " << c << std::endl;

	Fixed	d = Fixed(5.05f) * Fixed(2);
	std::cout << std::endl << "Ejemplo adicional: d = Fixed(5.05f) * Fixed(2)" << std::endl;
	std::cout << "d raw: " << d.getRawBits() << " -> d: " << d << std::endl;

	std::cout << std::endl << BRIGHT_MAGENTA << "Demostración: pre/post incremento y decremento" << RESET << std::endl;

	Fixed a_inc(3);
	std::cout << "a_inc start raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	Fixed b_post_inc = a_inc++;
	std::cout << "Después b_post_inc = a_inc++;" << std::endl;
	std::cout << "b_post_inc raw: " << b_post_inc.getRawBits() << " -> b_post_inc: " << b_post_inc << std::endl;
	std::cout << "a_inc raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	Fixed c_pre_inc = ++a_inc;
	std::cout << "Después c_pre_inc = ++a_inc;" << std::endl;
	std::cout << "c_pre_inc raw: " << c_pre_inc.getRawBits() << " -> c_pre_inc: " << c_pre_inc << std::endl;
	std::cout << "a_inc raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	Fixed a_dec(3);
	std::cout << std::endl << "a_dec start raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	Fixed b_post_dec = a_dec--;
	std::cout << "Después b_post_dec = a_dec--;" << std::endl;
	std::cout << "b_post_dec raw: " << b_post_dec.getRawBits() << " -> b_post_dec: " << b_post_dec << std::endl;
	std::cout << "a_dec raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	Fixed c_pre_dec = --a_dec;
	std::cout << "Después c_pre_dec = --a_dec;" << std::endl;
	std::cout << "c_pre_dec raw: " << c_pre_dec.getRawBits() << " -> c_pre_dec: " << c_pre_dec << std::endl;
	std::cout << "a_dec raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	return 0;
}