/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:18:55 by brivera           #+#    #+#             */
/*   Updated: 2026/01/03 17:41:08 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T* array, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif

