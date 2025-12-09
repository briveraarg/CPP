/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:24:36 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 21:58:04 by brivera          ###   ########.fr       */
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
static AForm* createShrub(const std::string& t)
{
	return (new ShrubberyCreationForm(t));
}

static AForm* createRobot(const std::string& t)
{
	return (new RobotomyRequestForm(t));
}

static AForm* createPardon(const std::string& t)
{ 
	return (new PresidentialPardonForm(t));
}

AForm* Intern::makeForm(const std::string& nameForm, const std::string& target)
{
	// tabla de formularios soportados 
	// Modo amigable: aceptamos variantes cortas 
	Entry table[] =
	{
		{SCF, &createShrub},
		{"shrubbery creation", &createShrub},
		{"shrubbery", &createShrub},

		{RRF, &createRobot},
		{"robotomy request", &createRobot},
		{"robotomy", &createRobot},

		{PPF, &createPardon},
		{"presidential pardon", &createPardon},
		{"pardon", &createPardon},
	};

	const int tableSize = sizeof(table) / sizeof(table[0]);

	for (int i = 0; i < tableSize; ++i)
	{
		if (nameForm == table[i].name)
		{
			AForm* f = table[i].creator(target);
			std::cout << "Intern creates " << nameForm << std::endl;
			return (f);
		}
	}
	// Si no se encuentra el nombre, lanzamos excepción para que el llamador
	// pueda gestionarlo con try/catch en lugar de comprobar un puntero NULL.
	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Intern::UnknownFormException: unknown form name");
}