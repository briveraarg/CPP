/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:11:21 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 20:05:01 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOUCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materias[MAX_MATERIA];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);
		
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
		
};

#endif