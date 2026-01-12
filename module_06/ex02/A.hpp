/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:24 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:46:27 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
	public:
		A() {}
		A(const A& other) : Base(other) {}
		A& operator=(const A& other) { 
			if (this != &other)
				Base::operator=(other);
			return (*this); 
		}
		~A() {}
};

#endif
