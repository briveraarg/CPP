/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 12:14:11 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>  // Para std::nothrow

/*
 *
 * Crea una horda de N zombies en una SOLA asignación de memoria
 * Parámetros:
 *   - N: número de zombies a crear
 *   - name: nombre que tendrán todos los zombies
 * 
 * Proceso:
 * 1. Asigna memoria para N zombies de una vez: new Zombie[N]
 * 2. Inicializa cada zombie con setName() ya que usamos constructor por defecto
 * 3. Retorna puntero al primer zombie del array
 * 
 * 
 * IMPORTANTE: El caller debe usar delete[] para liberar todo
 * 
*/

Zombie*	zombieHorde(int N, std::string name)
{
	int	i;

	if (N <= 0)
	{
		std::cerr << "Error: El número de zombies debe ser positivo!" << std::endl;
		return (NULL);
	}
	Zombie* horde = new(std::nothrow) Zombie[N];
	if (horde == NULL)
		return (NULL);
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		std::cout << "Zombie #" << i << " renombrado a: " << name << std::endl;
		i++;
	}
	std::cout << "\n¡Horda de " << N << " zombies '" << name << "' creada!" << std::endl;
	return (horde);
}
