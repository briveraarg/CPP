/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:00 by brivera           #+#    #+#             */
/*   Updated: 2026/02/04 16:47:47 by brivera          ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		
		void	_parseAndFill(int argc, char** argv);
		void	_printContent(const std::vector<int>& vector) const;
		void	_sortVector(std::vector<int>& arr);
		void	_sortPairs(std::vector<std::pair<int, int> >& pairs);
		void	_sortList(std::list<int>& arr);

		std::vector<int> _generateJacobsthal(int n);

	public:
		PmergeMe(void);
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute();
};

#endif