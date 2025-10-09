/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:24:49 by brivera           #+#    #+#             */
/*   Updated: 2025/10/09 19:13:50 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>


/***************************************/
/*                COLOR               */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

/*
 * Clase Harl - Representa un sistema de logging con diferentes niveles
 * 
 * Harl es como "Karen" - una persona que se queja en diferentes niveles:
 * - DEBUG: Información detallada para diagnóstico
 * - INFO: Información general del programa  
 * - WARNING: Advertencias de posibles problemas
 * - ERROR: Errores críticos que requieren intervención
 * 
 * Patrón utilizado: Command Pattern con punteros a funciones miembro
 */

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif