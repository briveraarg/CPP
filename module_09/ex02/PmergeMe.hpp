/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:00 by brivera           #+#    #+#             */
/*   Updated: 2026/02/03 14:00:06 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

class PmergeMe
{
	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		
		void _parseAndFill(int argc, char** argv);

		// Métodos para Vector
		void _sortVector(std::vector<int>& arr);
		//void _binaryInsertVector(std::vector<int>& mainChain, int value);

		// Métodos para List
		void _sortList(std::list<int>& arr);
		//void _binaryInsertList(std::list<int>& mainChain, int value);

	public:
		PmergeMe(void);
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute();
};

#endif