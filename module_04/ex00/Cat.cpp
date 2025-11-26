/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:40 by brivera           #+#    #+#             */
/*   Updated: 2025/11/25 20:18:49 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	type = "cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat operator assigned called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	 std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
std::cout << "_miau_" << std::endl;	
}
