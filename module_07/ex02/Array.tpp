/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:21:15 by brivera           #+#    #+#             */
/*   Updated: 2026/01/29 18:14:39 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include "color.hpp"


#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Array" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif


/* ========= constructors ========= */

template <typename T>
Array <T>::Array()
{
	this->_content = NULL;
	this->_size = 0;
	DBG_MSG("default constructor called");
}

template <typename T>
Array <T>::Array(unsigned int size)
{
	this->_content = new T[size]();
	this->_size = size; 
	DBG_MSG("size constructor called");
}

template <typename T>
Array <T>::Array(const Array& other)
{
	this->_content = new T[other._size]();
	this->_size = other._size;
	
	for (size_t i=0; i < other._size; i++)
	{
		this->_content[i] = other._content[i];
	}
	DBG_MSG("copy constructor called");
}

/* ========= destructor ========= */

template <typename T>
Array<T>::~Array()
{
	if (this->_content != NULL)
		delete[] this->_content;
	DBG_MSG("destructor called");
}

/* ========= operators ========= */

template <typename T>
Array<T>& Array<T>::operator = (const Array& other)
{
	if (this != &other)
	{
		if (this->_content != NULL)
			delete[] this->_content;
		this->_size = other._size;
		this->_content = new T[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
		{
			this->_content[i] = other._content[i];
		}
	}
	DBG_MSG("assignment operator called");
	return (*this);
}

template <typename T>
T& Array<T>::operator [] (unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->_content[index]);
}

template <typename T>
const T& Array<T>::operator [] (unsigned int index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->_content[index]);
}

/* ========= methodos ========= */

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}