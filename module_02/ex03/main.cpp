#include <iostream>
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point outside(10, 10);
	Point on_edge(5, 0);
	Point vertex(0, 0);

	const char* texto;
	const char* color;

	// caso 1
	if (bsp(a,b,c,inside))
	{
		texto = "Dentro";
		color = BRIGHT_GREEN;
	}
	else
	{
		texto = "Fuera o en borde";
		color = BRIGHT_RED;
	}
	std::cout << BRIGHT_CYAN << "(" << inside.getX() << "," << inside.getY() << ") -> " << color << BOLD << texto << RESET << std::endl;

	// caso 2
	if (bsp(a,b,c,outside))
	{
		texto = "Dentro";
		color = BRIGHT_GREEN;
	}
	else
	{
		texto = "Fuera o en borde";
		color = BRIGHT_RED;
	}
	std::cout << BRIGHT_CYAN << "(" << outside.getX() << "," << outside.getY() << ") -> " << color << BOLD << texto << RESET << std::endl;

	// caso 3
	if (bsp(a,b,c,on_edge))
	{
		texto = "Dentro";
		color = BRIGHT_GREEN;
	}
	else
	{
		texto = "Fuera o en borde";
		color = BRIGHT_RED;
	}
	std::cout << BRIGHT_CYAN << "(" << on_edge.getX() << "," << on_edge.getY() << ") -> " << color << BOLD << texto << RESET << std::endl;

	// caso 4
	if (bsp(a,b,c,vertex))
	{
		texto = "Dentro";
		color = BRIGHT_GREEN;
	}
	else
	{
		texto = "Fuera o en borde";
		color = BRIGHT_RED;
	}
	std::cout << BRIGHT_CYAN << "(" << vertex.getX() << "," << vertex.getY() << ") -> " << color << BOLD << texto << RESET << std::endl;

	return (0);
}
