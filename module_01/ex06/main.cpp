/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:18:13 by brivera           #+#    #+#             */
/*   Updated: 2025/10/13 12:34:44 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Uso: ./harlFilter [NIVEL]" << std::endl;
		std::cerr << "Niveles válidos: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}

	Harl harl;
	harl.filter(argv[1]);
	
	return (0);
}
