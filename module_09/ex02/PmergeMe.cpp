/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:51:52 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 16:46:29 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ========= constructores ========= */

PmergeMe::PmergeMe(void)
{
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

void PmergeMe::execute(std::vector<int> argument)
{
	if (argument.empty())
		return;

	_vector.clear();
	std::clock_t startVector = std::clock();
	_fillVector(argument);
	_sortVector(_vector);
	std::clock_t endVector = std::clock();
	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

	_list.clear();
	std::clock_t startList = std::clock();
	_fillList(argument);
	_sortList(_list);
	std::clock_t endList = std::clock();
	double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;

	_printTimeAndNumbers(timeList, timeVector, argument);
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
			throw std::runtime_error
				(BOLD BRIGHT_RED "Error:" RESET " Invalid input");
		vector.push_back(static_cast<int>(number));
	}
	return (vector);
}

/* ========= metodos privados ========= */

void PmergeMe::_sortVector(std::vector<int>& vector)
{
	if (vector.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pending;
	bool	hasStraggler = (vector.size() % 2 != 0);
	int		straggler = 0;

	if (hasStraggler)
		straggler = vector.back();
	_createPairsVector(vector, pairs);
	_sortPairsVector(pairs);
	_splitPairsVector(pairs, mainChain, pending);
	mainChain.insert(mainChain.begin(), pending[0]);
	_insertPendingVector(mainChain, pending);
	if (hasStraggler)
	{
		std::vector<int>::iterator pos = 
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	vector = mainChain;
}

void PmergeMe::_sortList(std::list<int>& list)
{
	if (list.size() <= 1)
		return ;
	
	std::list<std::pair<int,int> > pairs;
	std::list<int>	mainChain;
	std::list<int>	pending;
	bool	hasStraggler = (list.size() % 2 != 0);
	int		straggler = 0;

	if (hasStraggler)
	{
		straggler = list.back();
		list.pop_back();
	}
	_createPairsList(list, pairs);
	_sortPairsList(pairs);
	_splitPairsList(pairs, mainChain, pending);
	mainChain.insert(mainChain.begin(), pending.front());
	_insertPendingList(mainChain, pending);
	if (hasStraggler)
	{
		std::list<int>::iterator pos = 
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	list = mainChain;
}

void PmergeMe::_sortPairsVector(std::vector<std::pair<int, int> >& pairs)
{
	if (pairs.size() <= 1)
		return ;
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
	
	std::list<std::pair<int,int> >::iterator iLeft = left.begin();
	std::list<std::pair<int,int> >::iterator iRight = right.begin();
	std::list<std::pair<int,int> >::iterator iPairs = pairs.begin();
	// Merge
	while (iLeft != left.end() && iRight != right.end())
	{
		if (iLeft->first < iRight->first)
		{
			*iPairs = *iLeft;
			++iLeft;
		}
		else
		{
			*iPairs = *iRight;
			++iRight;
		}
		++iPairs;
	}
	while (iLeft != left.end())
	{
		*iPairs = *iLeft;
		++iLeft;
		++iPairs;
	}
	while (iRight != right.end())
	{
		*iPairs = *iRight;
		++iRight;
		++iPairs;
	}
}

std::vector<int> PmergeMe::_generateJacobsthal(size_t n)
{
	std::vector<int> jacobsthal;
	
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	size_t i = 2;
	while (true)
	{
		int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
		if (static_cast<size_t>(next) >= n)
			break;
		i++;
	}
	return (jacobsthal);
}

std::list<int> PmergeMe::_generateJacobsthalList(size_t n)
{
	std::list<int> jacobsthal;
	
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	int last = 1;
	int secondLast = 0;

	while (true)
	{
		int next = last + 2 * secondLast;
		jacobsthal.push_back(next);
		
		if (static_cast<size_t>(next) >= n)
			break;
		
		secondLast = last;
		last = next;
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

void PmergeMe::_insertPendingVector(std::vector<int>& mainChain, std::vector<int>& pending)
{
	std::vector<int> jacobsthal = _generateJacobsthal(pending.size());

	size_t lastPos = 1;
	
	for (size_t i = 2; i < jacobsthal.size(); i++)
	{
		size_t n = jacobsthal[i];
		if (n > pending.size())
			n = pending.size();

		for (size_t index = n - 1; index >= lastPos; index--)
		{
			int val = pending[index];
			std::vector<int>::iterator pos
				= std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
		}
		lastPos = n;
	}
}

void PmergeMe::_insertPendingList(std::list<int>& mainChain, std::list<int>& pending)
{
	std::list<int> jacobsthal = _generateJacobsthalList(pending.size());
	std::list<int>::iterator itJacobsthal = jacobsthal.begin();
	if (jacobsthal.size() > 2)
		std::advance(itJacobsthal, 2);
	size_t lastPos = 1;
	for (; itJacobsthal != jacobsthal.end(); ++itJacobsthal)
	{
		size_t n = *itJacobsthal;
		if (n > pending.size())
			n = pending.size();

		for (size_t index = n - 1; index >= lastPos; index--)
		{
			std::list<int>::iterator itPending = pending.begin();
			std::advance(itPending, index);
			int val = *itPending;
			
			std::list<int>::iterator pos =
				std::lower_bound(mainChain.begin(), mainChain.end(), val);
			mainChain.insert(pos, val);
		}
		lastPos = n;
	}
}

void PmergeMe::_splitPairsVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain, std::vector<int>& pending)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first); 
		pending.push_back(pairs[i].second);
	}
}

void PmergeMe::_splitPairsList(std::list<std::pair<int, int> >& pairs, std::list<int>& mainChain, std::list<int>& pending)
{
	std::list<std::pair<int, int> >::iterator it;
	for(it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pending.push_back(it->second);
	}
}

void PmergeMe::_createPairsVector(std::vector<int>& vector, std::vector<std::pair<int, int> >& pairs)
{
	size_t end = vector.size();
	if (vector.size() % 2 != 0)
		end -= 1;
		
	for (size_t i = 0; i < end; i += 2)
	{
		if (vector[i] > vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}
}

void PmergeMe::_createPairsList(std::list<int>& list, std::list<std::pair<int, int> >& pairs)
{
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
}

void PmergeMe::_printTimeAndNumbers(double& timeList, double& timeVector, std::vector<int>& argument)
{
	std::cout << BOLD << BRIGHT_GREEN << "Before: " << RESET;
	_printRange(argument.begin(), argument.end());
	std::cout << "\n";
	std::cout << BOLD << BRIGHT_GREEN << "After: " << RESET;
	_printRange(_vector.begin(), _vector.end());
	std::cout << "\n";
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with" << BOLD << " std::vector : " 
		<< timeVector  << " us" << RESET << std::endl;
	std::cout << "Time to process a range of " << _list.size()
		<< " elements with" << BOLD << " std::list   : "
		<< timeList << " us" << RESET << std::endl;
}

/* void PmergeMe::_printContent(const std::vector<int>& vector) const
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
} */

/*
template <typename Container>
Container _generateJacobsthal(int n)
{
	Container jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	
	int last = 1;
	int secondLast = 0;
	
	while (true)
	{
		int next = last + 2 * secondLast;
		jacobsthal.push_back(next);
		if (next >= n) break;
		secondLast = last;
		last = next;
	}
	return (jacobsthal);
}
*/

//imprimir pares
/* std::list<std::pair<int, int> >::iterator it;
for (it = pairs.begin(); it != pairs.end(); ++it)
{
	std::cout << "[" << it->first << ", " << it->second << "] ";
}
 */
