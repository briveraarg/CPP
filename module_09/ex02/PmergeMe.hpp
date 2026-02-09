/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:00 by brivera           #+#    #+#             */
/*   Updated: 2026/02/09 16:30:10 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <climits>

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BOLD			"\033[1m"

#define MAX_NUM			25

class PmergeMe
{
	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		
		/* métodos para ordenar en un vector */
		void	_sortVector(std::vector<int>& arr);
		void	_sortPairsVector(std::vector<std::pair<int, int> >& pairs);
		void	_insertPendingVector(std::vector<int>& mainChain, std::vector<int>& pending);
		void	_splitPairsVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain, std::vector<int>& pending);
		void	_createPairsVector(std::vector<int>& vector, std::vector<std::pair<int, int> >& pairs);
		void	_fillVector(std::vector<int> argument);
		
		/* métodos para ordenar en una lista */
		void	_sortPairsList(std::list<std::pair<int, int> >& pairs);
		void	_sortList(std::list<int>& arr);
		void	_insertPendingList(std::list<int>& mainChain, std::list<int>& pending);
		void	_splitPairsList(std::list<std::pair<int, int> >& pairs, std::list<int>& mainChain, std::list<int>& pending);
		void	_createPairsList(std::list<int>& list, std::list<std::pair<int, int> >& pairs);;
		void	_fillList(std::vector<int> argument);

		std::vector<int> _generateJacobsthal(size_t n);
		std::list<int> _generateJacobsthalList(size_t n);
		template <typename It>
		void _printRange(It begin, It end) const
		{
			int count = 0;
			for (; begin != end; ++begin)
			{
				std::cout << *begin << " ";
				++count;
				if (count == MAX_NUM)
				{
					std::cout << " [...]";
					break ;
				}
			}
			std::cout << std::endl;
		}

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute(std::vector<int>);
		std::vector<int>	parse(int argc, char** argv);
};

#endif

//void	_printContent(const std::vector<int>& vector) const;