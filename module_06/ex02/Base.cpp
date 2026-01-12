/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:45:49 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:45:52 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
}

Base::Base(const Base& other)
{
	(void)other;
}

Base& Base::operator=(const Base& other)
{
	(void)other;
	return (*this);
}

Base::~Base()
{
}
