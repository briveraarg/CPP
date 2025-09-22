/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:55:16 by brivera           #+#    #+#             */
/*   Updated: 2025/09/22 17:56:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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
	~Contact();
	
	// Métodos para establecer datos (setters)
	void	setFirstName(const std::string& name);
	void	setLastName(const std::string& name);
	void	setNickname(const std::string& nick);
	void	setPhoneNumber(const std::string& phone);
	void	setDarkestSecret(const std::string& secret);
	
	// Métodos para obtener datos (getters)
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;
	
	// Métodos de utilidad
	bool		isEmpty() const;			// Verificar si está vacío
	void		displayFull() const;		// Mostrar toda la información
};

#endif