/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/04 13:03:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

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

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed const & getX() const;
		Fixed const & getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
