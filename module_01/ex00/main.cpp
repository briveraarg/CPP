/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 12:32:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Main para probar las diferencias entre STACK y HEAP:
 * 1. newZombie() - Crea zombie en HEAP (necesita delete manual)
 * 2. randomChump() - Crea zombie en STACK (se destruye automáticamente)
 * 
 * Incluye verificación de memoria y buenas prácticas:
 * - Verificar punteros antes de usar
 * - Asignar NULL (nullprt para +11) después de delete para evitar dangling pointers
 *  - Colores para mejor visualización
 * 
*/

int main()
{
	std::cout << BOLD << BRIGHT_CYAN << "\n=== Prueba de HEAP vs STACK ===" << RESET << std::endl;
	
	std::cout << BOLD << BRIGHT_BLUE << "\n1. Zombie en HEAP:" << RESET << std::endl;
	Zombie* heapZombie = newZombie("HeapIria");
	if (heapZombie != NULL)
	{
		heapZombie->announce();
		std::cout << BOLD << "Destruyendo zombie del HEAP" << RESET << std::endl;
		delete heapZombie;
		heapZombie = NULL;
	}
	else
		std::cerr << BRIGHT_RED << "Error: No se pudo crear el zombie en HEAP" << RESET << std::endl;
	std::cout << BOLD << BRIGHT_GREEN << "\n2. Zombie en STACK:" << RESET << std::endl;
	randomChump("StackJorge");
	return (0);
}
