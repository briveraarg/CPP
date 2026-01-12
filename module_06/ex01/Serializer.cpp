/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:35:18 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:35:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ---- constructors and destructor ---- */

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
}

/* ---- serialize and  deserialize ---- */

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
