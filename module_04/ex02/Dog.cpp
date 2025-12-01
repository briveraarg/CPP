/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:00:14 by brivera           #+#    #+#             */
/*   Updated: 2025/12/01 12:25:59 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ---- Constructores y Destructor ---- */

Dog::Dog(void) : AAnimal("Dog")
{
	_brain = new Brain();
	std::cout << BOLD << "Dog" << RESET
			<< " default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	if (other._brain)
		_brain = new Brain(*other._brain);
	else
		_brain = new Brain();
	std::cout << BOLD << "Dog" << RESET
			<< " copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << BOLD << "Dog" << RESET
		<< " destructor called" << std::endl;
}

/* ---- Operador  ---- */

Dog& Dog::operator=(const Dog& other)
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
	std::cout << BOLD << "Dog" << RESET
			<< " copy assignment operator called" << std::endl;
	return (*this);
}

/* ---- Métodos ---- */

void	Dog::makeSound()	const
{
	std::cout << BOLD << "Dog" << RESET
			<< " says: woof!" << std::endl;	
}

std::string	Dog::getIdeaDog(size_t index) const
{
	if (!this->_brain)
		return (std::string());
	return (this->_brain->getIdeas(index));
}

void	Dog::setIdeaDog(size_t index, const std::string& idea)
{
	if (!this->_brain)
		return ;
	if (index >= 100)
		return ;
	this->_brain->setIdea(index, idea);
}

Brain* Dog::getBrain() const
{
	return (this->_brain);
}