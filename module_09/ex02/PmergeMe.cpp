/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:51:52 by brivera           #+#    #+#             */
/*   Updated: 2026/02/03 16:47:09 by brivera          ###   ########.fr       */
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

/* ========= metodos publicos ========= */

void PmergeMe::execute()
{
	if (_vector.empty())
		return;
	std::cout << "Before: ";
	_printContent(_vector);
	
	std::clock_t startDict1 = std::clock();
	_sortVector(_vector);
	std::clock_t endDict1 = std::clock();
	double timeDict1 = static_cast<double>(endDict1 - startDict1) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::clock_t startDict2 = std::clock();
	_sortList(_list);
	std::clock_t endDict2 = std::clock();
	double timeDict2 = static_cast<double>(endDict2 - startDict2) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::cout << "After:  ";
	_printContent(_vector);
	
	std::cout << "size " << _vector.size() << " std::vector : " << timeDict1 << " us" << std::endl;
	std::cout << "size " << _list.size() << " std::list : " << timeDict2 << " us" << std::endl;
}

/* ========= metodos privados ========= */

void PmergeMe::_sortVector(std::vector<int>& vector)
{
	if (vector.size() <= 1)
		return;

	std::vector<int> mainChain;
	std::vector<int> pend;
	bool	hasStraggler = (vector.size() % 2 != 0);
	size_t	end = vector.size();
	int		straggler = 0;

	if (hasStraggler)
		straggler = vector.back();
	if (hasStraggler)
		end -= 1;
	(void)straggler; // para compilar
	for (size_t i = 0; i < end; i += 2)
	{
		if (vector[i] > vector[i + 1])
		{
			mainChain.push_back(vector[i]);
			pend.push_back(vector[i + 1]);
		}
		else
		{
			mainChain.push_back(vector[i + 1]);
			pend.push_back(vector[i]);
		}
	}
}

void PmergeMe::_sortList(std::list<int>& arr)
{
	(void)arr;
}

void PmergeMe::_parseAndFill(int argc, char **argv)
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

void PmergeMe::_printContent(const std::vector<int>& vector) const
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}
