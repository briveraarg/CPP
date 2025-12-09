/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:27:28 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 12:10:40 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << BOLD << BRIGHT_GREEN
		<< "------ ex00 ------" << RESET << std::endl;

	Bureaucrat Ana;
	Bureaucrat Oli("Oliver", 6);
	std::cout << Ana << std::endl;
	std::cout << Oli << std::endl;

	std::cout << BRIGHT_GREEN
		<< "-- pruebas copia / asignación --" << RESET << std::endl;
	Bureaucrat copiaOli(Oli);
	std::cout << copiaOli << std::endl;
	Ana = Oli;
	std::cout << "Ana después de la asignación: " << Ana << std::endl;

	std::cout << BRIGHT_GREEN
		<< "-- pruebas incremento / decremento --" << RESET << std::endl;
	Bureaucrat t1("Iria", 2);
	std::cout << t1 << std::endl;
	t1.incrementGrade();
	std::cout << "después de incrementar (promover): " << t1 << std::endl;
	t1.decrementGrade();
	std::cout << "después de decrementar (degradar): " << t1 << std::endl;

	std::cout << BRIGHT_GREEN << "-- pruebas de excepciones --" << RESET << std::endl;
	try
	{
		Bureaucrat top("Top", MAX_GRADE);
		std::cout << top << std::endl;
		top.incrementGrade(); 
	}
	catch (const std::exception& e)
	{
		std::cerr << "capturada excepción: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat low("Low", MIN_GRADE);
		std::cout << low << std::endl;
		low.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "capturada excepción: " << e.what() << std::endl;
	}
	return (0);
}