/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:21:54 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 15:06:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Animal")
{
	std::cout << BOLD << "Animal" << RESET
				<< " default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type): type(type)
{
    std::cout << BOLD << "Animal (type: " << type << ")" << RESET
              << " default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << BOLD << "Animal" << RESET
				<< " copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << BOLD << "Animal" << RESET
				<< " copy assignment operator called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	 std::cout << BOLD << "Animal" << RESET
				<< " destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

/* ---- Función virtual pura ---- */

// void	AAnimal::makeSound() const
// {
// 	std::cout << BOLD << "AAnimal" << RESET
// 				<< " says: *generic animal sound*" << std::endl;
// }
