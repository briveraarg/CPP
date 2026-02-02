/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:51:52 by brivera           #+#    #+#             */
/*   Updated: 2026/02/02 18:39:03 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

/* ========= constructores ========= */

PmergeMe::PmergeMe(void)
{
}
PmergeMe::PmergeMe(int argc, char** argv)
{
    argc = argc + 1;
    std::cout << argv[1];
    //_parseAndFill(argc, argv);
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

/* ========= metodos ========= */


