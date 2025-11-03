#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2);
    Point outside(10, 10);
    Point on_edge(5, 0);
    Point vertex(0, 0);

    // Pruebas rápidas: cada línea muestra si el punto está estrictamente dentro
    // ("Dentro") o fuera / en borde ("Fuera o en borde").
    const char* resultado;

    if (bsp(a,b,c,inside))
        resultado = "Dentro";
    else
        resultado = "Fuera o en borde";
    std::cout << "dentro(2,2) -> " << resultado << std::endl;

    if (bsp(a,b,c,outside))
        resultado = "Dentro";
    else
        resultado = "Fuera o en borde";
    std::cout << "fuera(10,10) -> " << resultado << std::endl;

    if (bsp(a,b,c,on_edge))
        resultado = "Dentro";
    else
        resultado = "Fuera o en borde";
    std::cout << "en_borde(5,0) -> " << resultado << std::endl;

    if (bsp(a,b,c,vertex))
        resultado = "Dentro";
    else
        resultado = "Fuera o en borde";
    std::cout << "vertice(0,0) -> " << resultado << std::endl;

    return (0);
}
