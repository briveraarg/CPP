/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:21:18 by brivera           #+#    #+#             */
/*   Updated: 2026/01/16 12:30:21 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*				_content;
		unsigned int	_size;
	
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		virtual ~Array();

		Array&	operator=(const Array& other);
		T& operator[](unsigned int index) const;
		unsigned int size() const;
};
#include "Array.tpp"
#endif