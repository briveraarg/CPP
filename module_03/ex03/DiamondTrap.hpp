/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:20:00 by brivera           #+#    #+#             */
/*   Updated: 2025/11/15 18:41:07 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


/*
 * Nombre propio de DiamondTrap.
 * Intencionadamente usamos el mismo identificador que en ClapTrap
 * (por ejemplo `_name`) para seguir el enunciado del ejercicio.
 * Cuando necesitemos distinguir, accederemos explícitamente a la
 * versión de la clase base con `ClapTrap::_name`.
 *
 * Nota sobre los mensajes (constructores/destructores):
 * - El miembro privado `_name` de `DiamondTrap` contiene el nombre
 *   propio del DiamondTrap (ej. "Iria").
 * - La parte `ClapTrap` interna almacena `ClapTrap::_name`, que en
 *   DiamondTrap se inicializa como `name + "_clap_name"` (ej. "Iria_clap_name").
 * - Los mensajes impresos desde `FragTrap` o `ScavTrap` referirán a
 *   `ClapTrap::_name` (por eso ves "Iria_clap_name" en esos destructores),
 *   mientras que `DiamondTrap` usa su propio `_name`.
 * 
 */

/*
 * attack
 * - Declarado aquí para que DiamondTrap pueda delegar en la
 *   implementación de ScavTrap (comportamiento heredado).
*/

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string    _name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		
		DiamondTrap &operator=(const DiamondTrap &other);

		~DiamondTrap();

		void	whoAmI();
		void	attack(const std::string &target);
};

#endif
