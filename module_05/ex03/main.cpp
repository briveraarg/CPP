/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:18:07 by brivera           #+#    #+#             */
/*   Updated: 2025/12/10 13:29:32 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << BOLD << BRIGHT_BLUE 
		<< "--- ex03 ---" << RESET << std::endl;
	Intern someRandomIntern;
	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Taladrito");
		std::cout << *rrf << std::endl;
		std::cout << "-------------\n";
		scf = someRandomIntern.makeForm("shrubbery","Arbolito");
		std::cout << *scf << std::endl;
		std::cout << "-------------\n";
		ppf = someRandomIntern.makeForm("PresidentialPardonForm","Marvincito");
		std::cout << *ppf << std::endl;
		
		std::cout << "-------------\n";
		Bureaucrat ivan("Ivan", 25);
		std::cout << ivan << std::endl;
		ivan.signForm(*ppf);
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED 
			<< "Main caught: " << e.what()
			<< RESET << std::endl;
	}
	delete rrf;
	delete scf;
	delete ppf;
	return (0);
}