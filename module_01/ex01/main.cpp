/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 12:35:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 * Main para probar la función zombieHorde:
 * 1. Crear una horda de zombies con una sola asignación
 * 2. Hacer que cada zombie se anuncie usando while en lugar de for
 * 3. Liberar toda la memoria con delete[]
 * 
 * Conceptos clave:
 *  - new Zombie[N] vs new Zombie (diferencia entre arrays y objetos únicos)
 * - delete[] vs delete (para arrays vs objetos únicos) 
 * - Una sola asignación de memoria para múltiples objetos
 * 
*/

int main()
{
	int	horde_size;
	int	i;

	std::cout << BOLD << BRIGHT_CYAN << "\n=== Prueba de Horda de Zombies ===" << RESET << std::endl;
	horde_size = 5;
	std::string zombieName = "Jorges";
	std::cout << BOLD << BRIGHT_GREEN << "\n1. Creando horda de " << horde_size << " zombies:" << RESET << std::endl;
	Zombie* horde = zombieHorde(horde_size, zombieName);
	if (horde != NULL)
	{
		std::cout << BOLD << BRIGHT_BLUE << "\n2. Haciendo que cada zombie se anuncie:" << RESET << std::endl;
		i = 0;
		while (i < horde_size)
		{
			std::cout << "Zombie#" << i << ": ";
			horde[i].announce();
			i++;
		}
		std::cout << BOLD << BRIGHT_RED << "\n3. Destruyendo toda la horda:" << RESET << std::endl;
		delete[] horde;
		horde = NULL;
	}
	else
		std::cerr << BRIGHT_RED << "No se pudo crear la horda de zombies" << RESET << std::endl;
	return (0);
}
