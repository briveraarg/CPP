/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:50:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/17 17:59:44 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap& other);

        ScavTrap& operator=(const ScavTrap& other);

        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate();
};

#endif
