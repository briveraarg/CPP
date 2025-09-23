/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookInterface.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/09/23 20:14:52 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKINTERFACE_HPP
#define PHONEBOOKINTERFACE_HPP

#include "PhoneBook.hpp"
#include <string>

# ifndef TEST
#	define TEST 0
# endif

/*
** Funciones de interfaz de usuario para interactuar con PhoneBook
** Incluye validación de entrada y manejo de comandos
*/

void	runPhoneBookInterface(PhoneBook& phoneBook);
void	addContactInteractive(PhoneBook& phoneBook);
void	searchContactInteractive(const PhoneBook& phoneBook);
bool	getInput(const std::string& prompt, std::string& result);

/*
** Funciones de validación para entrada de datos
** Aseguran que los nombres y números de teléfono tengan formato correcto
*/

bool	isValidName(const std::string& name);
bool	isValidPhoneNumber(const std::string& phone);
bool	getValidatedInput(const std::string& prompt, std::string& result, const std::string& type);

#endif
