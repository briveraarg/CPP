/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:57:28 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 19:52:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "Error\n";
		std::cerr << "Example:\n\t./convert \"'a'\"" << std::endl;
		std::cerr << "\t./convert 42" << std::endl;
		std::cerr << "\t./convert 4.2f" << std::endl;
		std::cerr << "\t./convert 42.0" << std::endl;
		return (1);
	}
	std::string value = argv[1];
	ScalarConverter::convert(value);
	return (0);
}