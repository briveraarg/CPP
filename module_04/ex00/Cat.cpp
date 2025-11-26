/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:40 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 12:05:57 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << BOLD << "Cat" << RESET
			<< " default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << BOLD << "Cat" << RESET
			<< " copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << BOLD << "Cat" << RESET
			<< " copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	 std::cout << BOLD << "Cat" << RESET
		 << " destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << BOLD << "Cat" << RESET
			<< " says: meow!" << std::endl;	
}
