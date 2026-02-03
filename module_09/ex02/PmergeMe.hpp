/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:00 by brivera           #+#    #+#             */
/*   Updated: 2026/02/03 15:44:38 by brivera          ###   ########.fr       */
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
		
		void	_parseAndFill(int argc, char** argv);
		void	_printContent(const std::vector<int>& vector) const;
		void	_sortVector(std::vector<int>& arr);
		void	_sortList(std::list<int>& arr);

	public:
		PmergeMe(void);
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute();
};

#endif