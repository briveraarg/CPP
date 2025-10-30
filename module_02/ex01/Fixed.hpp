/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:49:04 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 12:55:14 by brivera          ###   ########.fr       */
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
 * Clase Fixed: representación en punto fijo con _fractionalBits = 8.
 *
 * Semántica relevante:
 * - El constructor desde float utiliza roundf (de <cmath>) para
 *   redondear al entero más cercano tras escalar por (1 << 8). Esto
 *   reduce el sesgo frente a la truncación directa.
 * - toFloat() reconstruye el valor flotante a partir del raw (_value / 256.0).
 * - toInt() devuelve la conversión a entero coherente con (int)toFloat(),
 *   es decir realiza truncamiento hacia 0. Esta decisión facilita la
 *   expectativa del usuario al llamar a toInt().
 */

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed(void);
		Fixed(const int	nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& other);

		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& a, const Fixed& fixed);
#endif