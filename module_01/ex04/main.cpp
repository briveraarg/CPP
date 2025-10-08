/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:23:56 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 17:02:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed_utils.hpp"

/*
 * Función que muestra el mensaje de error de uso
 * Utiliza colores para mejorar la legibilidad
 */

static void	msj_error(const std::string& program)
{
	std::cerr << BRIGHT_RED << BOLD << "Error: Modo de uso incorrecto" << RESET << std::endl;
	std::cerr << "Uso: " << RESET << BOLD << program 
			  << " <archivo> <s1> <s2>" << RESET << std::endl << std::endl;
	std::cerr << "  " << "archivo" << RESET << " : archivo a procesar" << std::endl;
	std::cerr << "  " << "s1" << RESET << "      : texto a buscar" << std::endl;
	std::cerr << "  " << "s2" << RESET << "      : texto de reemplazo" << std::endl << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (msj_error(argv[0]), 1);
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	outputFilename = filename + ".replace";
	std::ifstream inputFile;
	if (!open_InputFile(filename, inputFile))
		return (1);		
	std::string content = read_FileContent(inputFile);
	std::string processedContent = replace_AllOccurrences(content, s1, s2);
	if (!write_OutputFile(outputFilename, processedContent))
		return (1);
	return (0);
}
