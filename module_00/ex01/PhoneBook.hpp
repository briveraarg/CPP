/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:21 by brivera           #+#    #+#             */
/*   Updated: 2025/09/23 20:14:54 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define MAX_CONTACT		8
#define WIDTH			10

/*
** La clase PhoneBook gestiona una colección de hasta 8 contactos
** Implementa lógica circular para reemplazar contactos cuando está llena
** Proporciona métodos para añadir, mostrar y buscar contactos
*/

class PhoneBook
{
private:
	Contact		contacts[MAX_CONTACT];
	int			currentIndex;
	int			totalContacts;
	std::string	formatColumn(const std::string& text) const;
public:
	PhoneBook();
	~PhoneBook(void);

	void		addContact(const Contact& contact);
	void		displayAllContacts() const;
	void		displayContact(int index) const;
	int			getContactCount() const;
};

#endif