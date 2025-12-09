
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:06:38 by brivera           #+#    #+#             */
/*   Updated: 2025/12/05 19:40:01 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << BOLD << BRIGHT_BLUE << "--- ex01 ---" << RESET << std::endl;

	Bureaucrat director("Iria", 1);
	Bureaucrat jefe("Oliver", 25);
	Bureaucrat empleado("Ana", 75);
	Bureaucrat pasante("Brendi", 150);
	std::cout << BRIGHT_BLUE
			<< "Formulario válido y firma por distintos actores"
			<< RESET << std::endl;
	try
	{
		Form contrato("Contrato", 50, 25);
		std::cout << contrato << std::endl;

		std::cout << empleado << std::endl;
		empleado.signForm(contrato);
		std:: cout << "-----" << std::endl; 
		std::cout << jefe << std::endl;
		jefe.signForm(contrato);
		std:: cout << "-----" << std::endl; 
		std::cout << contrato << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED << "Exception: "
			<< e.what() << RESET << std::endl;
	}
	std::cout << BRIGHT_BLUE  "-----" << std::endl
				<< "Formularios con grados inválidos en el constructor"
				<< RESET << std::endl;
	try
	{
		Form invalidoAlto("InvalidoAlto", 0, 25); 
	}
	catch (const std::exception& e)
	{
		std::cout << "Constructor caught (alto): " 
			<< e.what() << RESET << std::endl;
	}

	try
	{
		Form invalidoBajo("InvalidoBajo", 151, 25);
	}
	catch (const std::exception& e)
	{
		std::cout << "Constructor caught (bajo): "
			 << e.what() << RESET << std::endl;
	}
	std:: cout << BRIGHT_BLUE << "-----" << std::endl
		<< "Intento de firmar con el burócrata más bajo"
		<< RESET << std::endl;
	try
	{
		Form hoja("HojaSimple", 150, 150);
		std::cout << hoja << std::endl;
		std:: cout << "-----" << std::endl;
		std::cout << pasante << std::endl;
		pasante.signForm(hoja); 
		std:: cout << "-----" << std::endl; 
		std::cout << hoja << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED
		<< "Exception: " << e.what() << RESET << std::endl;
	}
	std:: cout << BRIGHT_BLUE << "-----" << std::endl
		<< "Copiar y asignar Form y comprobar estado firmado"
		<< RESET << std::endl;
	try
	{
		Form original("Original", 50, 50);
		jefe.signForm(original);

		Form copia(original); 
		Form asignada = original;

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copia:    " << copia << std::endl;
		std::cout << "Asignada: " << asignada << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED << "Exception: "
			<< e.what() << RESET << std::endl;
	}
	std::cout << "---------\n";
	return (0);
}

