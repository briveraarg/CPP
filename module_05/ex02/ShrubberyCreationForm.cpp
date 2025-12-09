/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/08 12:50:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

#ifdef DEBUG
# define DBG_MSG_FORM(x) std::cout << BOLD << "ShrubberyCreationForm" << RESET << " " << x << std::endl
#else
# define DBG_MSG_FORM(x) ((void)0)
#endif

/* ---- Constructores y destructor  ---- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137), _target(target)
{
	DBG_MSG_FORM("parameterized constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	DBG_MSG_FORM("copy constructor called");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	DBG_MSG_FORM("destructor called");
}

/* ---- Operador  ---- */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	DBG_MSG_FORM("assignment operator called");
	return *this;
}

/* ---- Método  ---- */

void ShrubberyCreationForm::_executeAction(Bureaucrat const & executor) const
{
	(void)executor;
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		return;
	ofs << "       _-_-" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\\\" << std::endl;
	ofs.close();
}
