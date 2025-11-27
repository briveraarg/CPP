/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:32 by brivera           #+#    #+#             */
/*   Updated: 2025/11/27 18:22:13 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;
	
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);

		~Cat();

		void			makeSound() const;
		std::string		getIdeaCat(size_t index) const;
		void			setIdeaCat(size_t index, const std::string& idea);
		Brain*			getBrain() const;
};

#endif