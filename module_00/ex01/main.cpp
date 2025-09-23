/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:52:09 by brivera           #+#    #+#             */
/*   Updated: 2025/09/23 15:36:01 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBookInterface.hpp"


Contact	newContactTest(const std::string &fn, const std::string &ln,
		const std::string &nn, const std::string &pn, const std::string &ds)
{
	Contact		newContac;

	newContac.setFirstName(fn);
	newContac.setLastName(ln);
	newContac.setNickname(nn);
	newContac.setPhoneNumber(pn);
	newContac.setDarkestSecret(ds);
	return(newContac);
}

void	addContactTest(PhoneBook &phoneBook)
{
	phoneBook.addContact(newContactTest("Oliver King", "Zamora", "Oli", "156300258", ";)"));
	phoneBook.addContact(newContactTest("Iria", "Benaven", "Iria", "+54 154054796", ":P"));
	phoneBook.addContact(newContactTest("Noam", "Santander", "Noa", "15689295", "=D"));
	phoneBook.addContact(newContactTest("Raul", "Perez", "Raul", "4237169", ":D"));
	phoneBook.addContact(newContactTest("Freddy", "Rivas ", "Freddy", "156897452", ":)"));
	phoneBook.addContact(newContactTest("Patri", "Romagnoli ", "Pato", "+34 156897452", "=P"));
	phoneBook.addContact(newContactTest("Ana", "Ruiz Del Àrbol Fuente ", "Ana", "+34 15689742", "XD"));
}

int	main()
{
	PhoneBook	phoneBook;
	
	if (TEST == 1)
		addContactTest(phoneBook);
	runPhoneBookInterface(phoneBook);
	return (0);
}
