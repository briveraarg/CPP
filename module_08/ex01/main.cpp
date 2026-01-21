/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:22:04 by brivera           #+#    #+#             */
/*   Updated: 2026/01/21 14:45:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	Span	miVector(5);

	miVector.addNumber(1);
	miVector.addNumber(2);
	std::cout << miVector[1] << std::endl;
	return (0);
}