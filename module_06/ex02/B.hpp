/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:33 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:46:35 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B() {}
		B(const B& other) : Base(other) {}
		B& operator=(const B& other) { 
			if (this != &other)
				Base::operator=(other);
			return (*this); 
		}
		~B() {}
};

#endif
