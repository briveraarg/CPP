/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:15:24 by brivera           #+#    #+#             */
/*   Updated: 2025/12/10 17:08:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << BOLD << BRIGHT_MAGENTA 
		<< "--- ex02 ---" << RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << "------\n"
		<< "Creamos burócratas" << RESET << std::endl; 
	Bureaucrat iria("Iria", 1);
	Bureaucrat ana("Ana", 70);
	Bureaucrat oliver("Oliver", 140);
	Bureaucrat noam("Noam", 150);

	std::cout << BRIGHT_MAGENTA << "------\n"
		<< "Creamos los formularios" << RESET <<std::endl; 
	ShrubberyCreationForm shrub("Shrubbery");
	RobotomyRequestForm robot("Robotomy");
	PresidentialPardonForm pardon("Marvin");

	std::cout << BRIGHT_MAGENTA << "------\n"
		<< "FORMULARIO: ShrubberyCreationForm" << RESET << std::endl;
	std::cout << shrub << std::endl;
	std::cout << noam << std::endl;
	noam.signForm(shrub);
	std::cout << "---------\n";
	std::cout << oliver << std::endl;
	oliver.signForm(shrub);
	oliver.executeForm(shrub);
	std::cout << "---------\n";
	std::cout << iria << std::endl;
	iria.executeForm(shrub);

	std::cout << BRIGHT_MAGENTA << "------\n"
		<< "FORMULARIO: RobotomyRequestForm" << RESET <<std::endl;
	std::cout << ana << std::endl;
	std::cout << robot << std::endl;
	ana.signForm(robot);
	ana.executeForm(robot);
	std::cout << "---------\n";
	std::cout << iria << std::endl;
	iria.executeForm(robot);

	std::cout << BRIGHT_MAGENTA << "------\n"
		<< "FORMULARIO: PresidentialPardonForm" << RESET <<std::endl;
	std::cout << pardon << std::endl;
	std::cout << iria << std::endl;
	iria.executeForm(pardon);
	iria.signForm(pardon);
	iria.executeForm(pardon);
	std::cout << "---------\n";
	return (0);
}