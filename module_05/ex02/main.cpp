/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:15:24 by brivera           #+#    #+#             */
/*   Updated: 2025/12/08 13:54:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << BOLD << BRIGHT_MAGENTA<< "--- ex02 ---" << RESET << std::endl;

	// Creamos burócratas 
	Bureaucrat iria("Iria", 1);
	Bureaucrat ana("Ana", 70);
	Bureaucrat oliver("Oliver", 140);
	Bureaucrat noam("Noam", 150);

	// Formularios
	ShrubberyCreationForm shrub("casa");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Marvin");

	// Shrubbery: intentos de firma
	noam.signForm(shrub); // debe fallar (150 > 145)
	oliver.signForm(shrub); // debe tener éxito
	oliver.executeForm(shrub); // debe fallar (140 > 137)
	iria.executeForm(shrub); // Iria ejecuta con éxito

	// Robotomy: firma por Ana (70 <= 72), ejecución por Iria
	ana.signForm(robot);
	ana.executeForm(robot); // debe fallar (70 > 45)
	iria.executeForm(robot); // Iria ejecuta (resultado aleatorio)

	// Perdón: Iria puede firmar y ejecutar
	iria.signForm(pardon);
	iria.executeForm(pardon);

	// Intento de ejecutar un formulario sin firmar
	PresidentialPardonForm notSigned("Ford");
	ana.executeForm(notSigned); // debe informar que no puede ejecutar (no firmado)

	return (0);
}