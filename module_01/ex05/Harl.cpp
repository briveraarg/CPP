/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:24:30 by brivera           #+#    #+#             */
/*   Updated: 2025/10/09 19:15:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
 * Constructor - Inicializa Harl
 */

Harl::Harl(void)
{
	std::cout << "Harl ha entrado al restaurante" << std::endl;
}

/*
 * Destructor - Limpia Harl
 */

Harl::~Harl(void)
{
	std::cout << "Harl se ha ido del restaurante" << std::endl;
}

/*
 * DEBUG level: Mensajes de diagnóstico con información contextual
 */

void	Harl::debug(void)
{
	std::cout << BOLD << BRIGHT_GREEN << "[DEBUG]" << RESET << std::endl;
	std::cout << "I love having extra bacon for \
my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I really do!" << std::endl;
}

/*
 * INFO level: Información extensiva para rastrear ejecución
 */

void	Harl::info(void)
{
	std::cout << BOLD << BRIGHT_CYAN << "[INFO]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! \
If you did, I wouldn't be asking for more!" << std::endl;
}

/*
 * WARNING level: Advertencias de problemas potenciales
 */

void	Harl::warning(void)
{
	std::cout << BOLD << BRIGHT_MAGENTA << "[WARNING]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. \
I've been coming for years, whereas you started working here just last month."
	<< std::endl;
}

/*
 * ERROR level: Errores críticos irrecuperables
 */

 void	Harl::error(void)
{
	std::cout << BOLD << BRIGHT_RED << "[ERROR]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

/*
 * Método público complain - Selecciona el nivel apropiado de queja
 * Utiliza punteros a funciones miembro para mapear strings a métodos
 * void (Harl::*functions[])(void) -> Array de punteros a funciones miembro
 */

void	Harl::complain(std::string level)
{
	int i;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*functions[])(void) = 
	{
		&Harl::debug,
		&Harl::info, 
		&Harl::warning,
		&Harl::error
	};
	
	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
		i++;
	}
	std::cout << "[UNKNOWN]: Harl no sabe qué decir sobre '" << level << "'" << std::endl;
}
