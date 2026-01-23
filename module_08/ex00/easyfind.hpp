/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:43:07 by brivera           #+#    #+#             */
/*   Updated: 2026/01/23 15:01:13 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{return ("Element not found");}
};

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator R = std::find(container.begin(), container.end(), n);
	if (R == container.end())
		throw NotFoundException();
	return(R);
}

#endif