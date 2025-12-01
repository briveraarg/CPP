/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:40 by brivera           #+#    #+#             */
/*   Updated: 2025/12/01 12:25:36 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ---- Constructores y Destructor ---- */

Cat::Cat(void): AAnimal("Cat")
{
	_brain = new Brain();
	std::cout << BOLD << "Cat" << RESET
			<< " default constructor called" << std::endl;
	
}

Cat::Cat(const Cat& other): AAnimal(other)
{
	if (other._brain)
		_brain = new Brain(*other._brain);
	else
		_brain = new Brain();
	std::cout << BOLD << "Cat" << RESET
			<< " copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << BOLD << "Cat" << RESET
		 << " destructor called" << std::endl;
}

/* ---- Operador  ---- */

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		AAnimal::operator=(other);
	Brain* newBrain = NULL;
	if (other._brain)
		newBrain = new Brain(*other._brain);
	else
		newBrain = new Brain();
	delete this->_brain;
	this->_brain = newBrain;
	std::cout << BOLD << "Cat" << RESET
			<< " copy assignment operator called" << std::endl;
	return (*this);
}

/* ---- Métodos ---- */

void	Cat::makeSound() const
{
	std::cout << BOLD << "Cat" << RESET
			<< " says: meow!" << std::endl;	
}

std::string	Cat::getIdeaCat(size_t index) const
{
	if (!this->_brain)
		return (std::string());
	return (this->_brain->getIdeas(index));
}

void	Cat::setIdeaCat(size_t index, const std::string& idea)
{
	if (!this->_brain)
		return ;
	if (index >= 100)
		return ;
	this->_brain->setIdea(index, idea);
}

Brain* Cat::getBrain() const
{
	return (this->_brain);
}

