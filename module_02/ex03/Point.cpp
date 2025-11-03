#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// Constructor por defecto: inicializa a (0,0)
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// Constructor desde floats: convierte los valores a Fixed
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
	// Constructor de copia: copia los miembros const desde 'other'
}

// Nota: _x y _y son const, por lo que no se pueden reasignar aquí.
// Definimos el operador= para cumplir la forma canónica, pero no
// realizamos la asignación (usar el constructor de copia para crear
 // nuevas instancias con los mismos valores).
 
Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
	// Destructor vacío
}

Fixed const & Point::getX() const
{
	return (this->_x);
}

Fixed const & Point::getY() const
{
	return (this->_y);
}
