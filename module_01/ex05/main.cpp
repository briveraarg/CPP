/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:26:40 by brivera           #+#    #+#             */
/*   Updated: 2025/10/09 19:12:59 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(void)
{
	std::cout << BOLD 
	<< "\n======= ¡Bienvenido al Restaurante 42! =======" << RESET << std::endl;
	Harl harl;
	
	std::cout << BOLD
	<< "\n======= Probando todos los niveles de Harl ======= " << RESET << std::endl;
	
	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;
	
	harl.complain("ERROR");
	std::cout << std::endl;
	
	harl.complain("INVALID");
	harl.complain("debug");
	harl.complain("");
	harl.complain("CRITICAL");
		
	return (0);
}
