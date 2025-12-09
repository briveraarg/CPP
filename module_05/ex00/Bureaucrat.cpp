/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:39:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 12:12:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * Macro de depuración: habilitar definiendo DEBUG al compilar
 * (por ejemplo: make -C ex00 debug). Cuando DEBUG está definido,
 * DBG_MSG(x) imprimirá mensajes de seguimiento; en la compilación
 * normal DBG_MSG es una operación nula.
 */

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Bureaucrat" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

/*
 * Constructores
 * - El constructor por defecto crea un Bureaucrat con nombre "Default"
 *   y grado mínimo (peor).
 * - El constructor parametrizado valida el grado y lanza las excepciones
 *   definidas si el valor está fuera de los límites.
 * - El copy constructor copia nombre y grado.
 */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE)
{
	DBG_MSG("default constructor called");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name)
{
	DBG_MSG("parameterized constructor called");
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
			: _name(other._name), _grade(other._grade)
{
	DBG_MSG("copy constructor called");
}

/* ---- Destructor ---- */

Bureaucrat::~Bureaucrat()
{
	DBG_MSG("destructor called");
}

/*
 * Operador de asignación
 * Copia los campos desde 'other' salvo en caso de auto-asignación.
 */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	DBG_MSG("assignment operator called");
	return (*this);
}

/*
 * Getters públicos
 * Se devuelve el nombre por referencia const para evitar copias.
 */

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

/*
 * Modificadores de grado
 * - incrementGrade: promociona al burócrata (valor numérico menor).
 *   Lanza GradeTooHighException si ya está en el grado máximo.
 * - decrementGrade: degrada al burócrata (valor numérico mayor).
 *   Lanza GradeTooLowException si ya está en el grado mínimo.
 */

void Bureaucrat::incrementGrade()
{
	if (_grade <= MAX_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= MIN_GRADE)
		throw GradeTooLowException();
	++_grade;
}

/*
 * Implementación de what() para las excepciones anidadas.
 * Se devuelve una cadena literal con duración estática.
 */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

/*
 * Operador de salida para streams
 * Permite imprimir un Bureaucrat con: std::cout << b;
 */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}