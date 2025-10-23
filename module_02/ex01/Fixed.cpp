/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:40:44 by brivera           #+#    #+#             */
/*   Updated: 2025/10/23 14:42:48 by brivera          ###   ########.fr       */
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

#endif