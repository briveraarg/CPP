/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/12/08 12:50:00 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

#ifdef DEBUG
# define DBG_MSG_FORM(x) std::cout << BOLD << "RobotomyRequestForm" << RESET << " " << x << std::endl
#else
# define DBG_MSG_FORM(x) ((void)0)
#endif

static bool __robot_seeded = false;

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(target, 72, 45), _target(target)
{
	if (!__robot_seeded)
	{
		std::srand(std::time(NULL));
		__robot_seeded = true;
	}
	DBG_MSG_FORM("parameterized constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	DBG_MSG_FORM("copy constructor called");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	DBG_MSG_FORM("assignment operator called");
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	DBG_MSG_FORM("destructor called");
}

void RobotomyRequestForm::_executeAction(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << ": " << "Bzzzz... drilling noises..." << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}

