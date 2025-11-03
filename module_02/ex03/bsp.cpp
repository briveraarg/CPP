#include "Point.hpp"

// Epsilon en unidades 'raw' (1 -> 1/256 en valor real).
// Exponemos EPS_RAW como macro para que sea fácil de ajustar en tiempo de edición/compilación.
// Cambia el valor si prefieres una tolerancia diferente.
#define EPS_RAW 1 // unidad mínima en raw (1 == 1/(1<<_fractionalBits))

static const Fixed EPS(EPS_RAW);

static Fixed cross(Fixed const x1, Fixed const y1, Fixed const x2, Fixed const y2)
{
    // cross product z component for (x1,y1) x (x2,y2)
    return ((x1 * y2) - (y1 * x2));
}

// Valor absoluto para Fixed
static Fixed absFixed(Fixed v)
{
    if (v < Fixed(0))
        return (Fixed(0) - v);
    return (v);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // Implementación BSP usando producto cruz (2D z component)
    // Idea: para un triángulo ABC y un punto P, calcular los productos
    // cruzados entre cada arista y el vector hacia P. Si los tres tienen
    // el mismo signo (todos positivos o todos negativos), P está
    // estrictamente dentro. Si alguno es cero -> P está en el borde -> false.

    // Vectores: AB, BC, CA y AP, BP, CP
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed bcx = c.getX() - b.getX();
    Fixed bcy = c.getY() - b.getY();
    Fixed cax = a.getX() - c.getX();
    Fixed cay = a.getY() - c.getY();

    Fixed apx = point.getX() - a.getX();
    Fixed apy = point.getY() - a.getY();
    Fixed bpx = point.getX() - b.getX();
    Fixed bpy = point.getY() - b.getY();
    Fixed cpx = point.getX() - c.getX();
    Fixed cpy = point.getY() - c.getY();

    Fixed cross1 = cross(abx, aby, apx, apy);
    Fixed cross2 = cross(bcx, bcy, bpx, bpy);
    Fixed cross3 = cross(cax, cay, cpx, cpy);

    // Usar EPS porque puede haber pequeñas imprecisiones.
    // EPS está definido arriba como static const Fixed EPS(1).
    if (absFixed(cross1) <= EPS || absFixed(cross2) <= EPS || absFixed(cross3) <= EPS)
        return (false);

    // Comprobar signos estrictos
    bool all_pos = (cross1 > Fixed(0)) && (cross2 > Fixed(0)) && (cross3 > Fixed(0));
    bool all_neg = (cross1 < Fixed(0)) && (cross2 < Fixed(0)) && (cross3 < Fixed(0));

    return (all_pos || all_neg);
}
