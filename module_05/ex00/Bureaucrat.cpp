/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:39:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/04 19:33:40 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Debug macro: compilar con  -DDEBUG
// (Makefile target `debug`)

#ifdef DEBUG
# define DBG_MSG(x) std::cout << BOLD << "Bureaucrat" << RESET << " " << x << std::endl
#else
# define DBG_MSG(x) ((void)0)
#endif

// Constructors / Destructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE)
{
	DBG_MSG("default constructor called");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name)
{
	DBG_MSG("param constructor called");
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

Bureaucrat::~Bureaucrat()
{
	DBG_MSG("destructor called");
}

//operator =
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

// Getters
const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// Modifiers
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 <= MAX_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 >= MIN_GRADE)
		throw GradeTooLowException();
	++_grade;
}

// Exceptions what()
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

// Stream operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}