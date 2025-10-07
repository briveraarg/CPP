/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/07 12:33:21 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

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

/*
 * 
 * Diferencias con ex00:
 * 	- Constructor por defecto: necesario para crear arrays con new Zombie[N]
 * 	- Método setName(): para asignar nombres después de crear el array
 * 	- Soporta creación de hordas (arrays) de zombies en una sola asignación
 * 
 * Constructores:
 * 	- Zombie(): Constructor por defecto, crea zombie sin nombre
 * 	- Zombie(std::string name): Constructor con parámetro, inicializa con nombre
 * 
 * Métodos:
 * 	- announce(): Hace que el zombie se anuncie "name: BraiiiiiiinnnzzzZ..."
 * 	- setName(std::string name): Asigna un nombre al zombie
 * 
 * */

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
