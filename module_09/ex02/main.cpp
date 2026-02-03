/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:52:15 by brivera           #+#    #+#             */
/*   Updated: 2026/02/03 13:58:19 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	PmergeMe	pmergeMe(argc, argv);
	pmergeMe.execute();
	return (0);
}