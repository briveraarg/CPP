/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:46:10 by brivera           #+#    #+#             */
/*   Updated: 2026/01/12 12:46:13 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	public:
		Base();
		Base(const Base& other);
		Base& operator=(const Base& other);
		virtual ~Base();
};

#endif
