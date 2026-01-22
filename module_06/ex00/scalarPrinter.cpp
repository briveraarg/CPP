/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarPrinter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:31:51 by brivera           #+#    #+#             */
/*   Updated: 2025/12/19 19:47:14 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarPrinter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <climits>

bool my_isnan(double x)
{
    return (x != x);
}

bool my_isinf(double x)
{
    using std::numeric_limits;
    if (numeric_limits<double>::has_infinity)
        return (x == numeric_limits<double>::infinity()
            || x == -numeric_limits<double>::infinity());
    return (x > numeric_limits<double>::max() || x < -numeric_limits<double>::max());
}

std::string formatFloatValue(float f)
{
    std::ostringstream os;
    os << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f;
    std::string s = os.str();
    if (s.find_first_of("eE.") == std::string::npos)
        s += ".0";
    return (s);
}

std::string formatDoubleValue(double d)
{
    std::ostringstream os;
    os << std::setprecision(std::numeric_limits<double>::digits10 + 1) << d;
    std::string s = os.str();
    if (s.find_first_of("eE.") == std::string::npos)
        s += ".0";
    return (s);
}

void output_char_from_double(double value)
{
    if (my_isnan(value) || my_isinf(value))
        std::cout << "char: impossible" << std::endl;
    else
    {
        char ch = static_cast<char>(static_cast<int>(value));
        if (isprint(static_cast<unsigned char>(ch)))
            std::cout << "char: '" << ch << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
}

void output_int_from_double(double value)
{
    if (my_isnan(value) || my_isinf(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void output_float_from_double(double value)
{
    if (my_isnan(value))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    float f = static_cast<float>(value);
    if (my_isinf(value) || my_isinf(static_cast<double>(f)))
    {
        if (value < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: +inff" << std::endl;
    }
    else
    {
        std::cout << "float: " << formatFloatValue(f) << 'f' << std::endl;
    }
}

void output_double_from_double(double value)
{
    if (my_isnan(value))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (my_isinf(value))
    {
        if (value < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "double: " << formatDoubleValue(value) << std::endl;
    }
}
