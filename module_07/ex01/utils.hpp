/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:45:00 by brivera           #+#    #+#             */
/*   Updated: 2026/01/13 12:16:03 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

template <typename T>
void print(const T& x)
{
	std::cout << x << " ";
}

template <typename T>
void increment(T& x)
{
	x++;
}

template <typename T>
class	PrintLessThan
{
	private:
		const T _val;
	public:
		PrintLessThan(const T& v) : _val(v) {}
		void	operator()(const T& x)
		{
			if (x < _val)
				std::cout << x << " es menor que " << _val << std::endl;
		}
};

class	AddSuffix
{
	private:
		std::string	_suffix;
	public:
		AddSuffix(std::string s) : _suffix(s) {}
		void	operator()(std::string& s) { s += _suffix; }
};

#endif
