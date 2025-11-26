/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:06:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/26 16:06:03 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "color.hpp"

class	Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(const Brain& other);
		
		Brain&		operator=(const Brain& other);
		
		~Brain();

		std::string getIdeas(size_t index) const;
		void		setIdea(std::string idea);

};

#endif