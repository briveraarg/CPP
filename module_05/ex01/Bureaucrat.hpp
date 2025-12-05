/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:36:54 by brivera           #+#    #+#             */
/*   Updated: 2025/12/05 19:35:34 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

/***************************************/
/*                COLOR                */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

const int MAX_GRADE = 1;
const int MIN_GRADE = 150;

/*
 * Nota sobre excepciones y comportamiento de la clase:
 * - GradeTooHighException y GradeTooLowException son clases anidadas dentro de
 *   Bureaucrat. Heredan de std::exception y sobrescriben what() para proporcionar
 *   un mensaje descriptivo.
 * - Desde dentro de los métodos de Bureaucrat se lanzan así:
 *     throw GradeTooHighException();
 *   Desde fuera de la clase se puede lanzar/nombrar como:
 *     throw Bureaucrat::GradeTooHighException();
 * - Capture las excepciones por referencia (evita slicing):
 *     catch (const Bureaucrat::GradeTooHighException& e) { ... }
 *   También puede capturarse como std::exception: catch (const std::exception& e)
 * - La firma what() const throw() sigue la especificación clásica de C++98
 *   (equivalente a "no lanza excepciones"). Devuelve const char* a una cadena
 *   literal de duración estática, por lo que es seguro retornarla directamente.
 * - Las clases anidadas no tienen acceso implícito a los miembros de la instancia
 *   de Bureaucrat; son simplemente tipos declarados en el scope de la clase.
 * - Nota semántica: en esta implementación, un grado numérico menor es mejor
 *   (MAX_GRADE == 1). Por eso incrementGrade() reduce el valor de _grade
 *   (--_grade) para "promover" al burócrata.
 */

class Form; /* forward declaration used by signForm */

class Bureaucrat
{
	private:
		std::string		_name;
		int				_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		
		Bureaucrat& operator=(const Bureaucrat& other);
		
		~Bureaucrat();

		const std::string& getName() const;
		int		getGrade() const;
		void	signForm(class Form& f);
		void	incrementGrade();
		void	decrementGrade();

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
