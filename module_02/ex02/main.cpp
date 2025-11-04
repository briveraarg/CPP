/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:19:25 by brivera           #+#    #+#             */
/*   Updated: 2025/11/04 19:18:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* main subjet */

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << BRIGHT_CYAN << BOLD << "---- ex02 ----" << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA  << "valor de a: " << RESET;
	std::cout << a << std::endl;
	std::cout << BRIGHT_MAGENTA  << "valor de a (pre-incremento): " << RESET;
	std::cout << ++a << std::endl;
	std::cout << BRIGHT_MAGENTA  << "valor de a: " << RESET;
	std::cout << a << std::endl;
	std::cout << BRIGHT_MAGENTA  << "valor de a (pos-incremento): " << RESET;
	std::cout << a++ << std::endl;
	std::cout << BRIGHT_MAGENTA  << "valor de a: " << RESET;
	std::cout << a << std::endl;

	std::cout << BRIGHT_GREEN  << "valor de b: " << RESET;
	std::cout << b << std::endl;
	std::cout << BRIGHT_BLUE  << "valor MAX: " << RESET;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << BRIGHT_BLUE  << "valor MIN: " << RESET;
	std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}
