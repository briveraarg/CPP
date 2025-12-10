/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:02:33 by brivera           #+#    #+#             */
/*   Updated: 2025/12/10 12:52:59 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#define BOLD			"\033[1m"
#define RESET			"\033[0m"

/* Evita dependencias circulares: declaramos Bureaucrat aquí y
 * incluimos su definición completa en Form.cpp cuando sea necesario. */
class Bureaucrat;

/*
 * Clase AForm
 * Representa un formulario que puede ser firmado por un Bureaucrat si su
 * grado es suficientemente alto. Todos los atributos relevantes son privados
 * y algunos son constantes (nombre, grados requeridos).
 * 
 * -> void execute(Bureaucrat const & executor) const
 * 	Ejecuta el formulario: la implementación base
 * 	realiza las comprobaciones comunes
 * 	(si está firmado y si el ejecutor tiene suficiente grado)
 * 	y delega la acción concreta a _executeAction(). 
 * 	Esto evita repetir validaciones en cada clase que hereda de AForm.
 * 
 * -> virtual void _executeAction(Bureaucrat const & executor) const = 0;
 * 	Acción específica del formulario que deben implementar las clases
 * 	derivadas. Se invoca después de las comprobaciones realizadas por
 *  execute().
 * 
 */

class AForm
{
	private:
		const std::string    _name;
		bool                 _isSigned;
		const int            _signGrade;
		const int            _execGrade;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);

		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool               isSigned() const;
		int                getSignGrade() const;
		int                getExecGrade() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		void execute(Bureaucrat const & executor) const;

	protected:
		virtual void _executeAction(Bureaucrat const & executor) const = 0;
	
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif