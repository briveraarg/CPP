/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:45:00 by brivera           #+#    #+#             */
/*   Updated: 2025/09/23 15:53:16 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

/* 
 * Constructor: las strings se inicializan vacías automáticamente
 * Destructor: las strings se destruyen automáticamente 
 * De momento estan por buenas prácticas
*/

PhoneBook::PhoneBook()
{
	currentIndex = 0;
	totalContacts = 0;
}

PhoneBook::~PhoneBook(void)
{   }

/* 
 * Añadir contacto con lógica circular (máximo 8)
 * currentIndex = (currentIndex + 1) % MAX_CONTACT;
 */
void	PhoneBook::addContact(const Contact &contact)
{
	contacts[currentIndex] = contact;               
	currentIndex = (currentIndex + 1) % MAX_CONTACT;
	if (totalContacts < MAX_CONTACT)
		totalContacts++;
}

int	PhoneBook::getContactCount() const
{
	return (totalContacts);
}

std::string PhoneBook::formatColumn(const std::string &text) const
{
	if (text.length() > WIDTH)
		return (text.substr(0, 9) + ".");
	return (text);
}

void	PhoneBook::displayAllContacts() const
{
	int	i;

	if (totalContacts == 0)
	{
		std::cerr << "No contacts found." << std::endl;
		return ;
	}
	std::cout << std::setw(WIDTH) << "Index" << "|";
	std::cout << std::setw(WIDTH) << "First Name" << "|";
	std::cout << std::setw(WIDTH) << "Last Name" << "|";
	std::cout << std::setw(WIDTH) << "Nickname" << std::endl;
	i = 0;
	while (i < totalContacts)
	{
		std::cout << std::setw(WIDTH) << i << "|";
		std::cout << std::setw(WIDTH) << formatColumn(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(WIDTH) << formatColumn(contacts[i].getLastName()) << "|";
		std::cout << std::setw(WIDTH) << formatColumn(contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void	PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= totalContacts)
	{
		std::cerr << "Invalid index!" << std::endl;
		return ;
	}
	contacts[index].displayFull();
}
