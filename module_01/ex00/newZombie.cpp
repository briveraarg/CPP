/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 12:03:16 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>  // Para std::nothrow

/*
 * 
 * Crea un zombie en el HEAP usando 'new'
 * Retorna un puntero al zombie para que pueda ser usado fuera de esta función
 * IMPORTANTE: ¡El que llama esta función es responsable de eliminar este zombie!
 * 
 * Verificación de memoria:
 * 	- Usa std::nothrow para evitar excepciones
 * 	- Retorna nullptr si la asignación de memoria falla
 * 	- Siempre verificar el resultado antes de usar
 * 
 * Forma recomendada: declaración y asignación en la misma línea
 * Forma alternativa (separada, pero menos segura):
 *     Zombie* zombie;              // Declaración
 *     zombie = new Zombie(name);   // Asignación
 * 
*/

Zombie*	newZombie(std::string name)
{
	Zombie* zombie = new(std::nothrow) Zombie(name);
	if (zombie == NULL)
		return (NULL);
	return (zombie);
}
