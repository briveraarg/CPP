/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:09:23 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 12:19:31 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
 * Macro de depuración: habilitar definiendo DEBUG al compilar
 * (por ejemplo: make -C ex00 debug). Cuando DEBUG está definido,
 * DBG_MSG(x) imprimirá mensajes de seguimiento; en la compilación
 * normal DBG_MSG es una operación nula.
 */

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Form" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

/* ---- Constructores ---- */
/*
 * Constructor por defecto de Form.
 *
 * Crea un formulario con valores predeterminados:
 *  - Nombre "Default".
 *  - Estado sin firmar.
 *  - Grado de firma y ejecución en el valor máximo permitido.
 *
 * No realiza validaciones de rango porque usa los valores límite válidos.
 */

Form::Form() : _name("Default"), _isSigned(false), 
			_signGrade(MAX_GRADE), _execGrade(MAX_GRADE)
{
	DBG_MSG("default constructor called");
}

/*
 * Constructor parametrizado de Form.
 *
 * Inicializa un formulario con un nombre, un grado requerido para firmarlo
 * y un grado requerido para ejecutarlo. El formulario comienza sin firmar.
 *
 *  name Nombre del formulario (constante).
 *  signGrade Grado necesario para firmar el formulario.
 *  execGrade Grado necesario para ejecutar el formulario.
 *
 *  GradeTooHighException Si signGrade o execGrade son menores que MAX_GRADE.
 *  GradeTooLowException  Si signGrade o execGrade son mayores que MIN_GRADE.
 * 
 */

Form::Form(const std::string& name, int signGrade, int execGrade)
				: _name(name), _isSigned(false),
				_signGrade(signGrade), _execGrade(execGrade)
{
	DBG_MSG("parameterized constructor called");
	DBG_MSG("params: " << BOLD << name << ", signGrade: "
			<< signGrade << ", execGrade: " << execGrade);
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
}

/*
 *
 * Constructor de copia de Form.
 *
 * Crea un nuevo formulario copiando todos los atributos del formulario `other`.
 * Dado que los atributos son constantes (excepto _isSigned), se inicializan
 * directamente en la lista de inicialización.
 *
 * other Formulario a copiar.
 */
Form::Form(const Form& other)
		: _name(other._name), _isSigned(other._isSigned),
		_signGrade(other._signGrade), _execGrade(other._execGrade)
{
	DBG_MSG("copy constructor called");
}

/* ---- Destructor ---- */

Form::~Form()
{
	DBG_MSG("destructor called");
}

/* ---- Operador  ---- */

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	DBG_MSG("assignment operator called");
	return (*this);
}

/* ---- Getters publico ---- */

const std::string& Form::getName() const
{
	return (_name);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

/* ---- otros métodos ---- */

bool Form::isSigned() const
{
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

/*
 * Implementación de what() para las excepciones anidadas.
 * Se devuelve una cadena literal con duración estática.
 */

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

/**
 *  Sobrecarga del operador de inserción para Form.
 *
 * Permite imprimir la información de un formulario en un flujo de salida.
 * El formato incluye:
 *  - Nombre del formulario.
 *  - Estado de firma (yes/no).
 *  - Grado requerido para firmar.
 *  - Grado requerido para ejecutar.
 *
 * @param os Flujo de salida donde se escribe la información.
 * @param f  Form cuyo estado se quiere mostrar.
 *
 * @return std::ostream& El flujo de salida modificado.
 */

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", signed: ";
	if (f.isSigned())
		os << "yes";
	else
		os << "no";
	os << ", sign grade " << f.getSignGrade()
		<< ", exec grade " << f.getExecGrade();
	return (os);
}
