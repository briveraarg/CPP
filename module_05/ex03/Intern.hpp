/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:25:02 by brivera           #+#    #+#             */
/*   Updated: 2025/12/10 13:06:35 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm ;

#define SCF "ShrubberyCreationForm"
#define RRF "RobotomyRequestForm"
#define PPF "PresidentialPardonForm"

class Intern
{
	private:
		typedef AForm* (*creator_fn)(const std::string&);

		struct Entry
		{
			const char* name;
			creator_fn creator;
		};
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);
		AForm* makeForm(const std::string& typeForm, const std::string& target);

		class UnknownFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


#endif