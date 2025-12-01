/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:45:29 by brivera           #+#    #+#             */
/*   Updated: 2025/12/01 12:25:11 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ---- Constructores y Destructor ---- */

Brain::Brain(void)
{
	for (size_t i = 0; i < 100; ++i)
		_ideas[i] = "Empty idea";

	std::cout << BOLD << "Brain" << RESET
		<< " default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];

	std::cout << BOLD << "Brain" << RESET
		<< " copy constructor called" << std::endl;
}

Brain:: ~Brain()
{
	std::cout << BOLD << "Brain" << RESET
		<< " destructor called" << std::endl;
}

/* ---- Operador  ---- */

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	std::cout << BOLD << "Brain" << RESET
		<< " copy assignment operator called" << std::endl;
	return (*this);
}


/* ---- Métodos ---- */

std::string	Brain::getIdeas(size_t index) const
{
	if (index >= 100)
		return (std::string());
	return (this->_ideas[index]);
}

void	Brain::setIdea(size_t index, const std::string& idea)
{
	if (index >= 100)
		return ;

	_ideas[index] = idea;
}
