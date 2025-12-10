/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:24:36 by brivera           #+#    #+#             */
/*   Updated: 2025/12/10 13:13:19 by brivera          ###   ########.fr       */
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

/* ---- Métodos para crear los diferentes formularios ---- */

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

/* ---- Excepción ---- */

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Intern::UnknownFormException: unknown form name");
}

/**
 * Crea un formulario dinámicamente según el nombre solicitado.
 *
 * Esta función implementa el patrón Factory para generar distintos tipos
 * de formularios. El Intern no conoce los formularios concretos,
 * pero utiliza una tabla de correspondencia donde cada entrada asocia:
 *   - un nombre de formulario (string)
 *   - un puntero a función creadora (constructor)
 *
 * La función compara el nombre solicitado (`nameForm`) contra todas las
 * entradas de la tabla. Si encuentra una coincidencia, llama a la función
 * creadora correspondiente y devuelve un puntero a un nuevo AForm ubicado
 * en heap.
 *
 * Se permiten alias y variantes de cada nombre, haciéndolo flexible
 * y con posibilidades si se agregan nuevos formularios.
 *
 * @param nameForm 	Nombre del formulario a crear.
 * @param target   	Target del formulario, pasado al constructor
 * 					de la clase concreta.
 *
 * @return AForm*  	Puntero al formulario recién creado (propiedad transferida
 *                 	al main, quien debe liberar con `delete`).
 *
 * @throw 	Intern::UnknownFormException
 *        	Si el nombre del formulario no coincide con ninguna entrada
 * 			de la tabla.
 */

AForm* Intern::makeForm(const std::string& nameForm,
						const std::string& target)
{
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
			std::cout << BOLD << "Intern creates "
				<< RESET << nameForm << std::endl;
			return (f);
		}
	}
	throw Intern::UnknownFormException();
}
