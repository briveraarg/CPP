/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:00 by brivera           #+#    #+#             */
/*   Updated: 2026/02/06 18:13:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <climits>

class PmergeMe
{
	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		
		std::vector<int>	_parse(int argc, char** argv);
		//void	_printContent(const std::vector<int>& vector) const;
		void	_sortVector(std::vector<int>& arr);
		void	_sortPairs(std::vector<std::pair<int, int> >& pairs);
		void	_sortList(std::list<int>& arr);
		void	_fillVector(std::vector<int> argument);
		void	_fillList(std::vector<int> argument);

		template <typename It>
		void _printRange(It begin, It end) const
		{
			for (; begin != end; ++begin)
				std::cout << *begin << " ";
			std::cout << std::endl;
		}
		std::vector<int> _generateJacobsthal(int n);

	public:
		PmergeMe(void);
		//PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute(std::vector<int>);
		std::vector<int>	parse(int argc, char** argv);
};

#endif