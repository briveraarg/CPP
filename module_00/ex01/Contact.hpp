/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:55:16 by brivera           #+#    #+#             */
/*   Updated: 2025/09/23 20:14:59 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/*
** La clase Contact representa una entrada de contacto en la agenda telefónica
** Contiene variables miembro privadas para toda la información del contacto
** Proporciona métodos públicos para establecer y obtener datos del contacto
*/

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact();
	~Contact(void);
	
	void	setFirstName(const std::string& name);
	void	setLastName(const std::string& name);
	void	setNickname(const std::string& nick);
	void	setPhoneNumber(const std::string& phone);
	void	setDarkestSecret(const std::string& secret);
	
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	
	bool		isEmpty() const;
	void		displayFull() const;
};

#endif