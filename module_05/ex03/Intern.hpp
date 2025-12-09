/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:25:02 by brivera           #+#    #+#             */
/*   Updated: 2025/12/09 18:16:45 by brivera          ###   ########.fr       */
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
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);
		AForm* makeForm(std::string& nameForm, std::string& target);
};


#endif