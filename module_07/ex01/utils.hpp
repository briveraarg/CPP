/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:45:00 by brivera           #+#    #+#             */
/*   Updated: 2026/01/03 17:54:58 by brivera          ###   ########.fr       */
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

#endif
