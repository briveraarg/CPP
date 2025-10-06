/* **************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 15:57:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* **************************************************************************/

#include <iostream>
#include <string>
#include "colors.hpp"

/*
 * 
 * Ejercicio 02: "HI THIS IS BRAIN" + Pruebas con nullptr
 * 
 * Objetivo: Entender que las referencias son como tener otro nombre
 * para la misma cosa (como decir "mate" o "matecito" - es lo mismo)
 * 
 * PERO también ver qué pasa cuando intentamos hacer travesuras con nullptr
 * 
 * Analogía:
 * - Variable 'brain' = El mate original
 * - Puntero 'stringPTR' = La bombilla (necesitás usarla para acceder al mate)
 * - Referencia 'stringREF' = "El matecito" (otro nombre para el mismo mate)
 * 
 * Conceptos técnicos:
 * - Variable: acceso directo al valor
 * - Puntero: variable que guarda la dirección de otra variable
 * - Referencia: alias/sobrenombre para una variable existente
 * 
 * DIFERENCIA CLAVE con nullptr:
 * - Puntero: PUEDE ser nullptr (no apunta a nada)
 * - Referencia: NO PUEDE ser nullptr (siempre debe referenciar algo)
 * 
*/

int main()
{
	std::string brain = "HI IS THIS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << BOLD << BRIGHT_CYAN << "\n=== DIRECCIONES DE MEMORIA ===" << RESET << std::endl;
	std::cout << "Dirección de la variable brain:       " << &brain << std::endl;
	std::cout << "Dirección almacenada en stringPTR:    " << stringPTR << std::endl;
	std::cout << "Dirección de la referencia stringREF: " << &stringREF << std::endl;
	
	std::cout << BOLD << BRIGHT_GREEN << "\n=== VALORES ===" << RESET << std::endl;
	std::cout << "Valor de la variable brain:        " << brain << std::endl;
	std::cout << "Valor apuntado por stringPTR:      " << *stringPTR << std::endl;
	std::cout << "Valor de la referencia stringREF:  " << stringREF << std::endl;
	return (0);
}
