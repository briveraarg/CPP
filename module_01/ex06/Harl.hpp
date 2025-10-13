/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:24:49 by brivera           #+#    #+#             */
/*   Updated: 2025/10/13 12:37:20 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

/*
 * Clase Harl - Sistema de logging con filtrado por niveles
 * 
 * Para ex06: Implementa un filtro que muestra mensajes desde un nivel específico
 * hacia arriba usando switch statement:
 * - DEBUG: Muestra DEBUG, INFO, WARNING, ERROR
 * - INFO: Muestra INFO, WARNING, ERROR  
 * - WARNING: Muestra WARNING, ERROR
 * - ERROR: Muestra solo ERROR
 * 
 * Patrón utilizado: Switch statement con fall-through
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

		void	filter(std::string level);
};

#endif