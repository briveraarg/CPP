/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:35:46 by brivera           #+#    #+#             */
/*   Updated: 2026/01/22 15:10:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

#define BOLD			"\033[1m"
#define RESET			"\033[0m"

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "MutantStack" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

template <typename T>
MutantStack<T>::MutantStack(void)
{
	DBG_MSG("default constructor called");
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
	DBG_MSG("copy constructor called");
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
	{
		std::stack<T>::operator=(other);
	}
	DBG_MSG("assignment operator called");
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	DBG_MSG("destructor called");
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (this->c.end());
}