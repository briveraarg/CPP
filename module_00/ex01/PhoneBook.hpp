/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:21 by brivera           #+#    #+#             */
/*   Updated: 2025/09/22 19:16:05 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define MAX_CONTACT 8

class PhoneBook
{
private:
	Contact		contacts[MAX_CONTACT];	// Array estático de 8 contactos
	int			currentIndex;			// Índice actual para inserción circular
	int			totalContacts;			// Número total de contactos añadidos
	
	std::string	formatColumn(const std::string& text) const;  // Formatear columnas

public:
	PhoneBook();
	~PhoneBook();

	// Métodos básicos de gestión de contactos
	void		addContact(const Contact& contact);		// Añadir contacto
	void		displayAllContacts() const;				// Mostrar tabla de contactos
	void		displayContact(int index) const;		// Mostrar contacto específico
	int			getContactCount() const;				// Obtener número de contactos
};

#endif