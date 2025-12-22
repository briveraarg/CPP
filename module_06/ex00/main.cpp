/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:57:28 by brivera           #+#    #+#             */
/*   Updated: 2025/12/22 17:55:08 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>

void	msj_error()
{
	std::cerr << "Error\n";
	std::cerr << "Example:\n\t./convert \"'a'\"" << std::endl;
	std::cerr << "\t./convert 42" << std::endl;
	std::cerr << "\t./convert 4.2f" << std::endl;
	std::cerr << "\t./convert 42.0" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
		return (msj_error(), 1);
	std::string str = argv[1];
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isspace(str[i]))
			return (msj_error(), 1);
	}
	ScalarConverter::convert(str);
	return (0);
}