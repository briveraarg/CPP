/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:24:30 by brivera           #+#    #+#             */
/*   Updated: 2025/10/13 15:24:15 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
 * Constructor - Inicializa Harl
 */

Harl::Harl(void)
{
	// Constructor silencioso para ex06
}

/*
 * Destructor - Limpia Harl
 */

Harl::~Harl(void)
{
	// Destructor silencioso para ex06
}

/*
 * DEBUG level: Mensajes de diagnóstico con información contextual
 */

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for \
my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

/*
 * INFO level: Información extensiva para rastrear ejecución
 */

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding \
extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

/*
 * WARNING level: Advertencias de problemas potenciales
 */

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
		<< std::endl;
	std::cout << "I've been coming for years, \
whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

/*
 * ERROR level: Errores críticos irrecuperables
 */

 void	Harl::error(void)
{
	std::cerr << "[ ERROR ]" << std::endl;
	std::cerr << "This is unacceptable! \
I want to speak to the manager now." << std::endl;
}

/*
 * Método filter - Ejecuta desde el nivel especificado hacia los más severos
 * Utiliza switch statement con fall-through: DEBUG→INFO→WARNING→ERROR
 */

void	Harl::filter(std::string level)
{
	int	levelIndex;
	int	i;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	levelIndex = -1;
	i = 0;
	
	while (i < 4)
	{
		if (levels[i] == level)
		{
			levelIndex = i;
			break;
		}
		i++;
	}	
	switch (levelIndex)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cerr << UNKNOWN << std::endl;
			break ;
	}
}
