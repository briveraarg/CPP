/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:45:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 17:05:28 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_utils.hpp"

/*
 * Función que reemplaza todas las ocurrencias de s1 con s2 en el texto
 * Sin usar std::string::replace (prohibido en el ejercicio)
 * 1. Buscar primera ocurrencia de s1
 * 2. Mientras encontremos ocurrencias:
 *    - Agregar texto antes de la ocurrencia
 *    - Agregar s2 (reemplazo)
 *    - Mover posición después de la ocurrencia
 *    - Buscar siguiente
 * 3. Agregar resto del texto
 */

std::string	replace_AllOccurrences(const std::string& text,
            const std::string& s1, const std::string& s2)
{
	size_t		found;
	size_t		pos;
	std::string	result;

	pos = 0;
	if (s1.empty())
		return (text);		
	found = text.find(s1, pos);	
	while (found != std::string::npos)
	{
		result += text.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();		
		found = text.find(s1, pos);
	}
	result += text.substr(pos);
	return (result);
}

/*
 * Función que lee todo el contenido de un archivo preservando saltos de línea
 * getline() no incluye el \n, por eso lo agregamos manualmente
 * Excepto en la última línea (verificamos con eof())
 */

std::string	read_FileContent(std::ifstream& inputFile)
{
	std::string content;
	std::string line;
	
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += '\n';
	}
	inputFile.close();
	return (content);
}

/*
 * Función que abre un archivo de entrada y maneja errores
 * En C++98, ifstream requiere c_str() para convertir string a char*
 * Usa strerror(errno) para mensajes de error más descriptivos
 */
bool	open_InputFile(const std::string& filename, std::ifstream& inputFile)
{
	inputFile.open(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << BRIGHT_RED << "Error: '" << filename 
			<< "': " << std::strerror(errno) << RESET << std::endl;
		return (false);
	}
	return (true);
}

/*
 * Función que escribe el contenido procesado al archivo de salida
 * Crea el archivo .replace y maneja errores de escritura
 * Cierra automáticamente el archivo al finalizar
 */

bool	write_OutputFile(const std::string& outputFilename, const std::string& content)
{
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << BRIGHT_RED << "Error: '" << outputFilename 
			<< "': " << std::strerror(errno) << RESET << std::endl;
		return (false);
	}
	
	outputFile << content;
	outputFile.close();
	return (true);
}
