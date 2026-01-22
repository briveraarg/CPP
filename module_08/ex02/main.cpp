/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:20:34 by brivera           #+#    #+#             */
/*   Updated: 2026/01/22 15:18:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define RESET			"\033[0m"
#define BRIGHT_BLUE		"\033[94m"
#define BOLD			"\033[1m"

int main()
{
	std::cout << BOLD << BRIGHT_BLUE << "=== TEST MUTANT STACK (Subject) ===" << RESET << std::endl;
	
	MutantStack<int>	mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << BOLD << "\nIterando MutantStack..." << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << BOLD << BRIGHT_BLUE << "\n=== TEST LIST COMPARISON ===" << RESET << std::endl;
	
	std::list<int> l;
	l.push_back(5);
	l.push_back(17);
	l.pop_back();
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator itb_l = l.begin();
	std::list<int>::iterator ite_l = l.end();

	std::cout << BOLD << "Iterando std::list: " << RESET << std::endl;
	while (itb_l != ite_l)
	{
		std::cout << *itb_l << std::endl;
		itb_l++;
	}

	return 0;
}
