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


/***************************************/
/*                COLOR                */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

#include <iostream>
#include <string>


/*
** Ejercicio 02: "HI THIS IS BRAIN" - Guía Completa de Punteros vs Referencias
** 
** Objetivo: Entender todas las diferencias entre punteros y referencias
** con ejemplos prácticos y analogías argentinas
**
** Analogía del Mate:
** - Variable = El mate original
** - Puntero = La bombilla (necesitás usarla para acceder al mate)
** - Referencia = "El matecito" (otro nombre para el mismo mate)
**
** Regla de Oro:
** - USA REFERENCIAS cuando sea posible (90% de los casos)
** - USA PUNTEROS solo cuando necesites NULL, reasignación o memoria dinámica
*/
int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << BOLD << BRIGHT_CYAN << "\n=== EJEMPLO BÁSICO ===" << RESET << std::endl;
	std::cout << "Dirección de brain:     " << &brain << std::endl;
	std::cout << "Contenido de brain:     " << brain << std::endl;
	std::cout << "Dirección en stringPTR: " << stringPTR << std::endl;
	std::cout << "Contenido en stringPTR: " << *stringPTR << std::endl;
	std::cout << "Dirección de stringREF: " << &stringREF << std::endl;
	std::cout << "Contenido de stringREF: " << stringREF << std::endl;
	
	std::cout << BOLD << BRIGHT_BLUE << "\n=== NULL: SOLO PUNTEROS ===" << RESET << std::endl;
	std::string* null = NULL;
	std::cout << "Puntero: " << null << std::endl;
	
	std::cout << BOLD << BRIGHT_BLUE << "\n=== REASIGNACIÓN: SOLO PUNTEROS ===" << RESET << std::endl;
	std::string otro = "OTRA STRING";
	stringPTR = &otro;
	std::cout << "Puntero reasignado: " << *stringPTR << std::endl;
	std::cout << "Referencia sigue igual: " << stringREF << std::endl;
	
	std::cout << BOLD << BRIGHT_MAGENTA << "\n=== MODIFICACIÓN DE VALORES ===" << RESET << std::endl;
	brain = "OTRO BRAIN";
	std::cout << "brain cambiado a: " << brain << std::endl;
	std::cout << "stringREF refleja: " << stringREF << std::endl;
	
	std::cout << BOLD << BRIGHT_GREEN << "\n=== MEMORIA DINÁMICA ===" << RESET << std::endl;
	std::string *heapString = new std::string("HEAP BRAIN");
	std::string& heapREF = *heapString;

	std::cout << "Heap string: " << *heapString << std::endl;
	std::cout << "Heap ref: " << heapREF << std::endl;
	std::cout << "Direccion de memoria REF:" << &heapREF << std::endl;
	std::cout << "Direccion de memoria PTR:" << &heapString << std::endl;

	delete heapString;

	return (0);
}
