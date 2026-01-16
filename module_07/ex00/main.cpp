/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:58:21 by brivera           #+#    #+#             */
/*   Updated: 2026/01/14 15:03:23 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Fixed.hpp"

#define RESET			"\033[0m"
#define BRIGHT_GREEN	"\033[92m"


int main( void )
{
	double a = 3.14;
	double b = 2.14;

	std::cout << "\nValores de a y b" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "Aplicamos SWAP" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::cout << BRIGHT_GREEN << "\n******************" << RESET << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "\nValores de c y d" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "Aplicamos SWAP" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout << BRIGHT_GREEN << "\n******************" << RESET << std::endl;
	Fixed e(42.2f);
	Fixed f(24.2f);
	std::cout << "\nValores de e y f // class FIXED" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "Aplicamos SWAP" << std::endl;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << BRIGHT_GREEN << "------------------" << RESET << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	return (0);
}