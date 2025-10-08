/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:45:00 by brivera           #+#    #+#             */
/*   Updated: 2025/10/08 16:59:12 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_UTILS_HPP
#define SED_UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>

/***************************************/
/*                COLOR               */
/***************************************/

#define RESET			"\033[0m"
#define BRIGHT_RED		"\033[91m"
#define BRIGHT_GREEN	"\033[92m"
#define BRIGHT_BLUE		"\033[94m"
#define BRIGHT_MAGENTA	"\033[95m"
#define BRIGHT_CYAN		"\033[96m"

#define BOLD			"\033[1m"

/***************************************/
/*           FUNCTION PROTOTYPES       */
/***************************************/

std::string	replace_AllOccurrences(const std::string& text, 
            const std::string& s1, const std::string& s2);
std::string	read_FileContent(std::ifstream& inputFile);
bool	    open_InputFile(const std::string& filename, std::ifstream& inputFile);
bool	    write_OutputFile(const std::string& outputFilename,
            const std::string& content);

#endif
