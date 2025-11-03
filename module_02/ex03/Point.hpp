/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:00:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/03 20:52:08 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        // Point representa un punto 2D con coordenadas fijas (Fixed)
        // Los atributos son const para evitar mutaciones después de construir.
        Point(void);
        Point(float const x, float const y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        Fixed const & getX() const;
        Fixed const & getY() const;
};

#endif
