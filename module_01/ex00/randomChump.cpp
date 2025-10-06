/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 11:43:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** Crea un zombie en el STACK (variable local)
** Lo hace anunciarse a sí mismo
** El zombie se destruye automáticamente cuando esta función termina
**
** Diferencia clave con newZombie():
** - Se crea en STACK: Zombie zombie(name);  (sin 'new')
** - Se destruye automáticamente al salir del scope
** - No necesita 'delete' manual
*/

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
