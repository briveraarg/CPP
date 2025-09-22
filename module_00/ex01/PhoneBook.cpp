/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:45:00 by brivera           #+#    #+#             */
/*   Updated: 2025/09/22 19:14:40 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

// Constructor: inicializa los valores por defecto
PhoneBook::PhoneBook()
{
	currentIndex = 0;
	totalContacts = 0;
}

// Destructor: en este caso simple no necesita hacer nada especial
PhoneBook::~PhoneBook()
{   }

// Añadir contacto con lógica circular (máximo 8)
void	PhoneBook::addContact(const Contact& contact)
{
	contacts[currentIndex] = contact;               
	currentIndex = (currentIndex + 1) % MAX_CONTACT;
	
	if (totalContacts < MAX_CONTACT)
		totalContacts++;
}

// Obtener número de contactos actuales
int	PhoneBook::getContactCount() const
{
	return (totalContacts);
}

// Función auxiliar para formatear texto en columnas
std::string PhoneBook::formatColumn(const std::string& text) const
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");  // Truncar y añadir punto
	return (text);
}

// Mostrar tabla de todos los contactos
void	PhoneBook::displayAllContacts() const
{
	int	i;

	if (totalContacts == 0)
	{
		std::cerr << "No contacts found." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "\n";
	i = 0;
	while (i < totalContacts)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getNickname()) << "\n";
		i++;
	}
}

// Mostrar contacto específico
void	PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= totalContacts)
	{
		std::cerr << "Invalid index!" << std::endl;
		return ;
	}
	contacts[index].displayFull();
}
