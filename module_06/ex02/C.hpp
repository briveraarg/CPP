/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:41 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:46:42 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C() {}
		C(const C& other) : Base(other) {}
		C& operator=(const C& other) { 
			if (this != &other)
				Base::operator=(other);
			return (*this); 
		}
		~C() {}
};

#endif
