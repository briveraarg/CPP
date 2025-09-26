/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBookInterface.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/09/26 17:13:58 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBookInterface.hpp"
#include <iostream>
#include <string>

/*
** Valida nombres permitiendo solo letras, espacios, guiones y apostrofes
** Rechaza números y símbolos especiales
*/

bool	isValidName(const std::string &name)
{
	size_t	i;
	char	c;
	
	if (name.empty())
		return (false);
	i = 0;
	while (i < name.length())
	{
		c = name[i];
		if (!((c >= 'a' && c <= 'z') || 
			  (c >= 'A' && c <= 'Z') || 
			  c == ' ' || c == '-' || c == '\''))
			return (false);
		i++;
	}
	return (true);
}

/*
** Valida números de teléfono permitiendo números, espacios, guiones
** y el símbolo + solo al principio para códigos de país
*/

bool	isValidPhoneNumber(const std::string &phone)
{
	size_t	start;
	size_t	i;
	char	c;
	
	if (phone.empty())
		return (false);
	start = 0;
	if (phone[0] == '+')
		start = 1;
	i = start;
	while (i < phone.length())
	{
		c = phone[i];
		if (!((c >= '0' && c <= '9') || c == ' ' || c == '-'))
			return (false);
		i++;
	}
	
	return (true);
}

/*
** Obtiene entrada validada del usuario según el tipo especificado
** Repite la solicitud hasta obtener entrada válida o EOF
*/

bool	getValidatedInput(const std::string &prompt, 
		std::string &result, const std::string	&type)
{
	std::string	input;
	
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return (std::cerr << "\nEOF detected. Exiting..." << std::endl, false);
		if (input.empty())
		{
			std::cerr << "Field cannot be empty. Please try again." << std::endl;
			continue ;
		}
		if (type == "name" && !isValidName(input))
		{
			std::cerr << "Invalid name. Use only letters, spaces, hyphens and apostrophes." << std::endl;
			continue ;
		}
		else if (type == "phone" && !isValidPhoneNumber(input))
		{
			std::cerr << "Invalid phone number. Use only numbers, spaces, hyphens and + at the beginning." << std::endl;
			continue ;
		}
		result = input;
		return (true);
	}
}

/*
** Obtiene entrada del usuario que no puede estar vacía
** Retorna true si éxito, false si EOF
*/

bool	getInput(const std::string& prompt, std::string	&result)
{
	std::string	input;
	
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cerr << "\nEOF detected. Exiting..." << std::endl;
			return (false);
		}
		if (!input.empty())
		{
			result = input;
			return (true);
		}
		std::cerr << "Field cannot be empty. Please try again." << std::endl;
	}
}

void	addContactInteractive(PhoneBook &phoneBook)
{
	Contact		newContact;
	std::string	input;
	
	std::cout << "Adding new contact..." << std::endl;
	if (!getValidatedInput("First Name: ", input, "name")) 
		return ;
	newContact.setFirstName(input);
	if (!getValidatedInput("Last Name: ", input, "name"))
		return ;
	newContact.setLastName(input);	
	if (!getValidatedInput("Nickname: ", input, "name"))
		return ;
	newContact.setNickname(input);
	if (!getValidatedInput("Phone Number: ", input, "phone"))
		return ;
	newContact.setPhoneNumber(input);
		if (!getInput("Darkest Secret: ", input))
		return ;
	newContact.setDarkestSecret(input);
	phoneBook.addContact(newContact);
	std::cout << "Contact added successfully!" << std::endl;
}

void	searchContactInteractive(const PhoneBook& phoneBook)
{
	int	index;

	if (phoneBook.getContactCount() == 0)
	{
		std::cerr << "No contacts available." << std::endl;
		return ;
	}
	phoneBook.displayAllContacts();
	std::string input;
	std::cout << "Enter index to display: ";
	if (!std::getline(std::cin, input))
	{
		std::cerr << "\nEOF detected. Exiting..." << std::endl;
		return ;
	}
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		index = input[0] - '0';
		phoneBook.displayContact(index);
	}
	else
		std::cerr << "Invalid index!" << std::endl;
}

void runPhoneBookInterface(PhoneBook &phoneBook)
{
	std::string command;
	
	std::cout << "\nWelcome to the 80s PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cerr << "\nEOF detected. Exiting..." << std::endl;
			break ;
		}
		if (command == "ADD")
			addContactInteractive(phoneBook);
		else if (command == "SEARCH")
			searchContactInteractive(phoneBook);
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else
			std::cerr << "Invalid command. Use ADD, SEARCH, or EXIT."
			<< std::endl;
	}
}
