/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:57:28 by brivera           #+#    #+#             */
/*   Updated: 2025/12/17 18:15:44 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "Error\n Uso: ./convert a" << std::endl;
		return (1);
	}
	std::string valor = argv[1];
	ScalarConverter::convert(valor);
	return(0);
}