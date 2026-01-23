/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:21:16 by brivera           #+#    #+#             */
/*   Updated: 2026/01/23 15:14:36 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTANCK_HPP
#define MUTANTSTANCK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack(void);
		MutantStack(const MutantStack& other);
		
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;
    	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"
#endif