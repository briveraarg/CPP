/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:00:07 by brivera           #+#    #+#             */
/*   Updated: 2025/10/27 19:06:20 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
		
	std::cout << BRIGHT_GREEN << "Valores iniciales:" << RESET << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
	
	std::cout << BRIGHT_MAGENTA << "Modificamos el valor de a" << RESET << std::endl;
	a.setRawBits(2855);
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	
	std::cout << BRIGHT_CYAN << "Modificamos el valor de c = b" << RESET << std::endl;
	c = b;
	b.setRawBits(25);
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
	
	std::cout << BRIGHT_RED << "Modificamos el valor de b" << RESET << std::endl;
	b.setRawBits(768);
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
	return (0);
}
