/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:51:52 by brivera           #+#    #+#             */
/*   Updated: 2026/02/03 14:21:03 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>

/* ========= constructores ========= */

PmergeMe::PmergeMe(void)
{
}
PmergeMe::PmergeMe(int argc, char** argv)
{
	_parseAndFill(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->_list = other._list;
	this->_vector = other._vector;
}

/* ========= operador ========= */

PmergeMe&  PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_list = other._list;
		this->_vector = other._vector;
	}
	return (*this);
}

/* ========= destructor ========= */

PmergeMe::~PmergeMe()
{
}

/* ========= metodos ========= */

void PmergeMe::execute()
{
	if (_vector.empty())
		return;
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
	
	std::clock_t startDict1 = std::clock();
	_sortVector(_vector);
	std::clock_t endDict1 = std::clock();
	double timeDict1 = static_cast<double>(endDict1 - startDict1) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::clock_t startDict2 = std::clock();
	_sortList(_list);
	std::clock_t endDict2 = std::clock();
	double timeDict2 = static_cast<double>(endDict2 - startDict2) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::cout << "After:  ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "size " << _vector.size() << " std::vector : " << timeDict1 << " us" << std::endl;
	std::cout << "size " << _list.size() << " std::list : " << timeDict2 << " us" << std::endl;
}

void PmergeMe::_sortVector(std::vector<int>& arr)
{
	(void)arr;
}

void PmergeMe::_sortList(std::list<int>& arr)
{
	(void)arr;
}

void	PmergeMe::_parseAndFill(int argc, char **argv)
{
	long	number;
	char*	endPtr;

	for(int i = 1; i < argc; i++)
	{
		number = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || std::string(argv[i]).empty())
			throw std::runtime_error("Error: Invalid input");

		_vector.push_back(static_cast<int>(number));
		_list.push_back(static_cast<int>(number));
	}
}
