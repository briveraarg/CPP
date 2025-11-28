/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:00:14 by brivera           #+#    #+#             */
/*   Updated: 2025/11/28 16:24:02 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ---- Constructores y Destructor ---- */

Dog::Dog(void) : Animal("Dog")
{
	std::cout << BOLD << "Dog" << RESET
			<< " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << BOLD << "Dog" << RESET
			<< " copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);	
	std::cout << BOLD << "Dog" << RESET
			<< " copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << BOLD << "Dog" << RESET
		<< " destructor called" << std::endl;
}

/* ---- Métodos ---- */

void	Dog::makeSound()	const
{
	std::cout << BOLD << "Dog" << RESET
			<< " says: woof!" << std::endl;	
}