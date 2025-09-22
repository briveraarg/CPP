/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:55:08 by brivera           #+#    #+#             */
/*   Updated: 2025/09/22 19:02:43 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iostream>

// Constructor: las strings se inicializan vacías automáticamente
Contact::Contact()
{   }

// Destructor: las strings se destruyen automáticamente
Contact::~Contact()
{   }

// ======== SETTERS (para poner valores) ========
void	Contact::setFirstName(const std::string &name)
{
	firstName = name;
}

void	Contact::setLastName(const std::string &name)
{
	lastName = name;
}

void	Contact::setNickname(const std::string &nick)
{
	nickname = nick;
}

void	Contact::setPhoneNumber(const std::string &phone)
{
	phoneNumber = phone;
}

void	Contact::setDarkestSecret(const std::string &secret)
{
	darkestSecret = secret;
}

// ======== GETTERS (para obtener valores) ========
std::string	Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

// ======== MÉTODOS DE UTILIDAD ========
bool Contact::isEmpty() const
{
	return (firstName.empty() && lastName.empty() && 
			nickname.empty() && phoneNumber.empty() && 
			darkestSecret.empty());
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
