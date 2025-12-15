/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:57:28 by brivera           #+#    #+#             */
/*   Updated: 2025/12/15 17:01:56 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cerr << "Error\n Uso: ./ex00 a" << std::endl;
		return (1);
	}
	std::string valor = argv[1];
	ScalarConverter::convert(valor);
	return(0);
}