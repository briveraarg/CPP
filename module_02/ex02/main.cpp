/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:19:25 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 13:32:35 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << "Demostración: resta en Fixed (raw y float)" << std::endl;

	Fixed a(3);            // representa 3.0
	Fixed b(1.5f);         // representa 1.5

	std::cout << "a raw: " << a.getRawBits() << " -> a: " << a << std::endl;
	std::cout << "b raw: " << b.getRawBits() << " -> b: " << b << std::endl;

	Fixed c = a - b;
	std::cout << std::endl << "c = a - b" << std::endl;
	std::cout << "c raw: " << c.getRawBits() << " -> c: " << c << std::endl;

	Fixed d = Fixed(5.05f) * Fixed(2);
	std::cout << std::endl << "Ejemplo adicional: d = Fixed(5.05f) * Fixed(2)" << std::endl;
	std::cout << "d raw: " << d.getRawBits() << " -> d: " << d << std::endl;

	/* Demostración de pre/post incremento y decremento */
	std::cout << std::endl << "Demostración: pre/post incremento y decremento" << std::endl;

	Fixed a_inc(3); // 3.0
	std::cout << "a_inc start raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	Fixed b_post_inc = a_inc++; // devuelve valor antiguo
	std::cout << "Después b_post_inc = a_inc++;" << std::endl;
	std::cout << "b_post_inc raw: " << b_post_inc.getRawBits() << " -> b_post_inc: " << b_post_inc << std::endl;
	std::cout << "a_inc raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	Fixed c_pre_inc = ++a_inc; // incrementa y devuelve nuevo valor
	std::cout << "Después c_pre_inc = ++a_inc;" << std::endl;
	std::cout << "c_pre_inc raw: " << c_pre_inc.getRawBits() << " -> c_pre_inc: " << c_pre_inc << std::endl;
	std::cout << "a_inc raw: " << a_inc.getRawBits() << " -> a_inc: " << a_inc << std::endl;

	/* Decrementos */
	Fixed a_dec(3); // 3.0
	std::cout << std::endl << "a_dec start raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	Fixed b_post_dec = a_dec--; // devuelve valor antiguo
	std::cout << "Después b_post_dec = a_dec--;" << std::endl;
	std::cout << "b_post_dec raw: " << b_post_dec.getRawBits() << " -> b_post_dec: " << b_post_dec << std::endl;
	std::cout << "a_dec raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	Fixed c_pre_dec = --a_dec; // decrementa y devuelve nuevo valor
	std::cout << "Después c_pre_dec = --a_dec;" << std::endl;
	std::cout << "c_pre_dec raw: " << c_pre_dec.getRawBits() << " -> c_pre_dec: " << c_pre_dec << std::endl;
	std::cout << "a_dec raw: " << a_dec.getRawBits() << " -> a_dec: " << a_dec << std::endl;

	return 0;
}