/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:51:52 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 11:16:56 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ========= constructores ========= */

PmergeMe::PmergeMe(void)
{
}

/* PmergeMe::PmergeMe(int argc, char** argv)
{
	_parse(argc, argv);
 */

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

void PmergeMe::execute(std::vector<int> argument)
{
	if (argument.empty())
		return;

	std::clock_t startDict1 = std::clock();
	_fillVector(argument);
	_sortVector(_vector);
	std::clock_t endDict1 = std::clock();
	double timeDict1 = static_cast<double>(endDict1 - startDict1) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::clock_t startDict2 = std::clock();
	_fillList(argument);
	_sortList(_list);
	std::clock_t endDict2 = std::clock();
	double timeDict2 = static_cast<double>(endDict2 - startDict2) / CLOCKS_PER_SEC * 1000000; // microsegundos

	std::cout << "Before: ";
	_printRange(argument.begin(), argument.end());
	std::cout << "After list:  ";
	_printRange(_list.begin(), _list.end());
	std::cout << "After vector:  ";
	_printRange(_vector.begin(), _vector.end());
	std::cout << "size " << _vector.size() << " std::vector : " << timeDict1 << " us" << std::endl;
	std::cout << "size " << _list.size() << " std::list : " << timeDict2 << " us" << std::endl;
}

std::vector<int> PmergeMe::parse(int argc, char **argv)
{
	long				number;
	char*				endPtr;
	std::vector<int> 	vector;

	for(int i = 1; i < argc; i++)
	{
		number = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || std::string(argv[i]).empty()
			|| number > INT_MAX)
			throw std::runtime_error("Error: Invalid input");

		vector.push_back(static_cast<int>(number));
	}
	return (vector);
}
/* ========= metodos privados ========= */

void PmergeMe::_sortVector(std::vector<int>& vector)
{
	if (vector.size() <= 1)
		return;
	// 1. Emparejar elementos (ganador, perdedor)
	std::vector<std::pair<int, int> > pairs;
	
	bool	hasStraggler = (vector.size() % 2 != 0);
	size_t	end = vector.size();
	int		straggler = 0;

	if (hasStraggler)
	{
		straggler = vector.back();
		end -= 1;
	}
	for (size_t i = 0; i < end; i += 2)
	{
		// En first guardamos el MAYOR (ganador), en second el MENOR (perdedor)
		if (vector[i] > vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}

	// 2. Ordenar recursivamente los pares basándose en el elemento 'first' (el mayor)
	_sortPairsVector(pairs);

	std::vector<int> mainChain;
	std::vector<int> pending;


	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first); 
		pending.push_back(pairs[i].second);  
	}
	mainChain.insert(mainChain.begin(), pending[0]);

	std::vector<int> jacobsthal = _generateJacobsthal(pending.size());

	size_t lastPos = 1;
	
	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		size_t n = jacobsthal[i];
		if (n > pending.size())
			n = pending.size();

		for (size_t index = n - 1; index >= lastPos; index--)
		{
			// Elemento a insertar
			int val = pending[index];
			
			// Binary Search
			std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
		}
		
		lastPos = n;
	}

	// Insertar el straggler si existe
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	vector = mainChain;
}

void PmergeMe::_sortList(std::list<int>& list)
{
	if (list.size() <= 1)
		return ;
	
	std::list<std::pair<int,int> > pairs;
	
	bool	hasStraggler = (list.size() % 2 != 0);
	int		straggler = 0;

	if (hasStraggler)
	{
		straggler = list.back();
		list.pop_back();
	}
	std::list<int>::iterator i = list.begin();
	while (i != list.end())
	{
		int first = *i;
		i++;
		int second = *i;
		i++;
		
		if (first > second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
	//imprimir pares
	std::list<std::pair<int, int> >::iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		std::cout << "[" << it->first << ", " << it->second << "] ";
	}//borrar
	std::cout << std::endl;
	_sortPairsList(pairs);
	(void) straggler; //borrar

}

void PmergeMe::_sortPairsVector(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return;
	
	size_t mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

	_sortPairsVector(left);
	_sortPairsVector(right);

	// Merge
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i].first < right[j].first)
			pairs[k++] = left[i++];
		else
			pairs[k++] = right[j++];
	}
	while (i < left.size())
		pairs[k++] = left[i++];
	while (j < right.size())
		pairs[k++] = right[j++];
}

void PmergeMe::_sortPairsList(std::list<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return ;
	
	size_t mid = pairs.size() / 2;
	std::list<std::pair<int,int> >::iterator it = pairs.begin();
	std::advance(it, mid);
	std::list<std::pair<int,int> > left(pairs.begin(), it);
	std::list<std::pair<int,int> > right(it, pairs.end());

	_sortPairsList(left);
	_sortPairsList(right);
}
std::vector<int> PmergeMe::_generateJacobsthal(int n)
{
	std::vector<int> jacobsthal;
	
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	int i = 2;
	while (true)
	{
		int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
		if (next >= n)
			break;
		i++;
	}
	return (jacobsthal);
}

void PmergeMe::_fillVector(std::vector<int> argument)
{
	for (size_t i = 0; i < argument.size(); i++)
	{
		_vector.push_back(argument[i]);
	}
}

void PmergeMe::_fillList(std::vector<int> argument)
{
	for (size_t i = 0; i < argument.size(); i++)
	{
		_list.push_back(argument[i]);
	}
}

/* void PmergeMe::_printContent(const std::vector<int>& vector) const
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
} */
