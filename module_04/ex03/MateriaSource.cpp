/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:11:21 by brivera           #+#    #+#             */
/*   Updated: 2025/11/29 20:13:06 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ------ constructors ------ */

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materias[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

/* ------ destructor ------ */

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

/* ------ operator ------ */

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = NULL;
		}
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return (*this);
}

/* ------ methods ------ */

/*
 * Si está lleno, borramos m para evitar leaks (asumiendo que nos pasan ownership)
 * O simplemente lo ignoramos si el subject dice "nothing happens".
 * Para seguridad, si no lo guardamos, lo mejor es borrarlo o avisar.
 * En este caso, lo borramos para evitar leaks en el main.
 * 
*/

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << "MateriaSource learned " << m->getType() << std::endl;
			return ;
		}
	}
	delete m;
	std::cout << "MateriaSource is full, materia deleted" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			return (this->_materias[i]->clone());
		}
	}
	return (0);
}
