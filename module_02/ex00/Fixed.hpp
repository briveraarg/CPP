/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:51 by brivera           #+#    #+#             */
/*   Updated: 2025/10/22 20:05:52 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/***************************************/
/*                COLOR                */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

/*
 * La Forma Canónica Ortodoxa (Orthodox Canonical Form):
 *  0. constructor por defecto  Fixed(void);
 * 	1. constructor de copia -> Fixed(const Fixed& other)
 *  2. operador de asignacion -> Fixed& operator=(const Fixed& other);
 *  3. destructor -> ~Fixed();
 * 
*/

class   Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
