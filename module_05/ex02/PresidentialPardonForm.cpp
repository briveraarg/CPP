/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/08 12:50:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#ifdef DEBUG
# define DBG_MSG_FORM(x) std::cout << BOLD << "PresidentialPardonForm" << RESET << " " << x << std::endl
#else
# define DBG_MSG_FORM(x) ((void)0)
#endif

/* ---- Constructores y Destructor ---- */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(target, 25, 5), _target(target)
{
	DBG_MSG_FORM("parameterized constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
	DBG_MSG_FORM("copy constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	DBG_MSG_FORM("destructor called");
}

/* ---- Operador  ---- */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	DBG_MSG_FORM("assignment operator called");
	return (*this);
}

/* ---- Método ---- */

void	PresidentialPardonForm::_executeAction(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& f)
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