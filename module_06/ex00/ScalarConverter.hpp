/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:59:01 by brivera           #+#    #+#             */
/*   Updated: 2025/12/15 16:55:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
 
class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void convert(const std::string& argument);

};

#endif