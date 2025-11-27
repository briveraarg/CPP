/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:21:54 by brivera           #+#    #+#             */
/*   Updated: 2025/11/27 18:55:53 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("Animal")
{
	std::cout << BOLD << "Animal" << RESET
				<< " default constructor called" << std::endl;
}

Animal::Animal(const std::string& type): type(type)
{
    std::cout << BOLD << "Animal (type: " << type << ")" << RESET
              << " default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << BOLD << "Animal" << RESET
				<< " copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << BOLD << "Animal" << RESET
				<< " copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	 std::cout << BOLD << "Animal" << RESET
				<< " destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << BOLD << "Animal" << RESET
				<< " says: *generic animal sound*" << std::endl;
}
