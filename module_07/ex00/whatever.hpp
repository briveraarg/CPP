/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:03:14 by brivera           #+#    #+#             */
/*   Updated: 2026/01/03 16:20:16 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif