/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:02:33 by brivera           #+#    #+#             */
/*   Updated: 2025/12/05 19:33:30 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

/* Evita dependencias circulares: declaramos Bureaucrat aquí y
 * incluimos su definición completa en Form.cpp cuando sea necesario. */
class Bureaucrat;

/*
 * Clase Form
 * Representa un formulario que puede ser firmado por un Bureaucrat si su
 * grado es suficientemente alto. Todos los atributos relevantes son privados
 * y algunos son constantes (nombre, grados requeridos).
 */

class Form
{
	private:
		const std::string    _name;
		bool                 _isSigned;
		const int            _signGrade;
		const int            _execGrade;

	public:
		Form();
		Form(const std::string& name, int signGrade, int execGrade);
		Form(const Form& other);

		Form& operator=(const Form& other);
		~Form();

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif