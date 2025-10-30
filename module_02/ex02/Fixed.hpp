/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:40 by brivera           #+#    #+#             */
/*   Updated: 2025/10/30 17:41:46 by brivera          ###   ########.fr       */
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

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;
	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& other);

		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/* Operadores de comparación */
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		/* Operadores aritméticos */
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		/* Incremento / decremento */
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		/* Funciones estáticas min/max */
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& a, const Fixed& fixed);

#endif


