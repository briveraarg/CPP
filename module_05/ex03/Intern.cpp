/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:24:36 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 18:16:55 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
 * Macro de depuración: habilitar definiendo DEBUG al compilar
 * (por ejemplo: make -C ex00 debug). Cuando DEBUG está definido,
 * DBG_MSG(x) imprimirá mensajes de seguimiento; en la compilación
 * normal DBG_MSG es una operación nula.
 */

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Intern" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

/* ---- Constructores y Destructor ---- */

Intern::Intern()
{
	DBG_MSG("default constructor called");
}

Intern::Intern(const Intern& other)
{
	(void)other;
	DBG_MSG("copy constructor called");
}

Intern::~Intern()
{
	DBG_MSG("default destructor called");
}

/* ---- Operador ---- */

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return(*this);
}

/* ---- Métodos ---- */

AForm* Intern::makeForm(std::string& nameForm, std::string& target)
{
	AForm*	form;
	int		type;
	std::string typeForm[3] = {SCF, RRF, PPF};

	
	return(form);
}