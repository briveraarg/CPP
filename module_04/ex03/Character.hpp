/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:09:23 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 19:09:53 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

#define MAX_SLOT 4

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	_inventory[MAX_SLOT];

	public:
		Character(void);
		Character(std::string const & name);
		Character(const Character& other);
		~Character(void);

		Character& operator=(const Character& other);
		
		std::string const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};


#endif