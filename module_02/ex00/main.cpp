/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:00:07 by brivera           #+#    #+#             */
/*   Updated: 2025/10/22 20:13:33 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	// Para que 'a' represente el valor 5.0 (5 * 256 = 1280)
	a.setRawBits(1280);
	
	Fixed	b(a);  // b se construye como copia de a
	Fixed	c;     // c se construye con valor 0
	
	std::cout << "Valores iniciales:" << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;
	
	// Modificar a no afecta a b (son independientes)
	a.setRawBits(512);  // Cambiar a a 2.0
	std::cout << "\nDespués de modificar a:" << std::endl;
	std::cout << "a: " << a.getRawBits() << " (cambiado a 2.0)" << std::endl;
	std::cout << "b: " << b.getRawBits() << " (sigue siendo 5.0)" << std::endl;
	
	// c = b copia el valor de b a c
	c = b;
	std::cout << "\nDespués de c = b:" << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << " (ahora igual a b)" << std::endl;
	
	// Modificar b no afecta a c (son independientes después de la asignación)
	b.setRawBits(768);  // Cambiar b a 3.0
	std::cout << "\nDespués de modificar b:" << std::endl;
	std::cout << "b: " << b.getRawBits() << " (cambiado a 3.0)" << std::endl;
	std::cout << "c: " << c.getRawBits() << " (sigue siendo 5.0)" << std::endl;
	
	return (0);
}