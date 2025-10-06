/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/06 15:30:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	std::cout << "Zombie sin nombre creado" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie " << this->name << " creado" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destruido" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
