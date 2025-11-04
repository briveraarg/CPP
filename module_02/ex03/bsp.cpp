#include "Point.hpp"

/*
 * Epsilon en unidades 'raw' (1 -> 1/256 en valor real).
 * EPS_RAW como macro para que sea fácil de ajustar.
 * unidad mínima en raw (1 == 1/(1<<_fractionalBits))
 * 
*/

#define EPS_RAW 1 

static const Fixed EPS(EPS_RAW);

static Fixed cross(Fixed const x1, Fixed const y1, Fixed const x2, Fixed const y2)
{
	return ((x1 * y2) - (y1 * x2));
}

static Fixed absFixed(Fixed v)
{
	if (v < Fixed(0))
		return (Fixed(0) - v);
	return (v);
}

static Fixed crossPoint(Point const &a, Point const &b, Point const &p)
{
	Fixed abx = b.getX() - a.getX();
	Fixed aby = b.getY() - a.getY();
	Fixed apx = p.getX() - a.getX();
	Fixed apy = p.getY() - a.getY();
	return (cross(abx, aby, apx, apy));
}

/*
 * Devuelve true si p está sobre la arista ab (dentro de la tolerancia EPS)
*/

static bool	pointOnEdge(Point const &a, Point const &b, Point const &p)
{
	Fixed c = crossPoint(a, b, p);
	return (absFixed(c) <= EPS);
}

/*
 * Comprueba si tres productos cruzados tienen el mismo signo
*/
static bool	sameSign(Fixed c1, Fixed c2, Fixed c3)
{
	bool all_pos = (c1 > Fixed(0)) && (c2 > Fixed(0)) && (c3 > Fixed(0));
	bool all_neg = (c1 < Fixed(0)) && (c2 < Fixed(0)) && (c3 < Fixed(0));
	return (all_pos || all_neg);
}

/*
 *
 * Implementación BSP usando producto cruz (2D z component)
 * Idea: para un triángulo ABC y un punto P, calcular los productos
 * cruzados entre cada arista y el vector hacia P. Si los tres tienen
 * el mismo signo (todos positivos o todos negativos), P está
 * estrictamente dentro. Si alguno es cero -> P está en el borde -> false.
 * Vectores: AB, BC, CA y AP, BP, CP
 * 
*/

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed cross1 = crossPoint(a, b, point);
	Fixed cross2 = crossPoint(b, c, point);
	Fixed cross3 = crossPoint(c, a, point);

	if (pointOnEdge(a, b, point) || pointOnEdge(b, c, point) || pointOnEdge(c, a, point))
		return (false);
	return (sameSign(cross1, cross2, cross3));
}
