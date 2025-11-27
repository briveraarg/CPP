/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:02:24 by brivera           #+#    #+#             */
/*   Updated: 2025/11/27 18:22:21 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Dog : public Animal
{
	private:
		Brain*	_brain;
	
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);

		~Dog();
		
		void    		makeSound() const;
		std::string		getIdeaDog(size_t index) const;
		void			setIdeaDog(size_t index, const std::string& idea);
		Brain*			getBrain() const;

};

#endif