/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:21:51 by brivera           #+#    #+#             */
/*   Updated: 2025/11/30 20:27:17 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "color.hpp"

int main(void)
{
	/* --- SUBJECT TEST --- */
	std::cout << BOLD << BRIGHT_BLUE << "------ TEST DEL SUBJECT ------" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* ana = new Character("Ana");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		ana->equip(tmp);
		tmp = src->createMateria("cure");
		ana->equip(tmp);
		
		ICharacter* oli = new Character("Oli");
		ana->use(0, *oli);
		ana->use(1, *oli);
		
		delete oli;
		delete ana;
		delete src;
	}

	/* --- DEEP COPY TEST --- */
	std::cout << std::endl << BOLD << BRIGHT_BLUE << "------ TEST DE COPIA PROFUNDA ------" << RESET << std::endl;
	{
		Character* iria = new Character("Iria");
		iria->equip(new Ice());
		iria->equip(new Cure());

		// Copia profunda usando constructor de copia
		Character* copy = new Character(*iria);
		
		std::cout << "Nombre original: " << iria->getName() << std::endl;
		std::cout << "Nombre copia: " << copy->getName() << std::endl;

		// Modificar copia para verificar independencia
		std::cout << "Equipando Ice a la copia (slot 2)..." << std::endl;
		copy->equip(new Ice());

		ICharacter* oli = new Character("Oli");
		
		std::cout << "Original usa items:" << std::endl;
		iria->use(0, *oli); // Ice
		iria->use(1, *oli); // Cure
		iria->use(2, *oli); // Empty -> nada

		std::cout << "Copia usa items:" << std::endl;
		copy->use(0, *oli); // Ice
		copy->use(1, *oli); // Cure
		copy->use(2, *oli); // Ice (nuevo)

		delete iria;
		delete copy;
		delete oli;
	}

	/* --- UNEQUIP TEST --- */
	std::cout << std::endl << BOLD << BRIGHT_BLUE << "------ TEST DE UNEQUIP ------" << RESET << std::endl;
	{
		ICharacter* ana = new Character("Ana");
		AMateria* m = new Ice();
		
		ana->equip(m);
		ICharacter* oli = new Character("Oli");
		
		std::cout << "Usando slot 0:" << std::endl;
		ana->use(0, *oli);

		std::cout << "Desequipando slot 0..." << std::endl;
		ana->unequip(0);
		
		std::cout << "Usando slot 0 (no deberia hacer nada):" << std::endl;
		ana->use(0, *oli);

		// Importante: unequip no borra la memoria, debemos hacerlo nosotros para evitar leaks
		delete m;
		delete ana;
		delete oli;
	}
	
	/* --- FULL INVENTORY TEST --- */
	std::cout << std::endl << BOLD << BRIGHT_BLUE << "------ TEST DE INVENTARIO LLENO ------" << RESET << std::endl;
	{
		ICharacter* ana = new Character("Ana");
		AMateria* m1 = new Ice();
		AMateria* m2 = new Cure();
		AMateria* m3 = new Ice();
		AMateria* m4 = new Cure();
		AMateria* m5 = new Ice(); // Extra

		ana->equip(m1);
		ana->equip(m2);
		ana->equip(m3);
		ana->equip(m4);
		
		std::cout << "Intentando equipar 5to item..." << std::endl;
		ana->equip(m5); // Should fail or print message

		delete ana;
		// Si equip falló, m5 no es propiedad del personaje, hay que borrarlo
		// Nota: Depende de tu implementación de equip. Si equip no toma ownership al fallar, borramos.
		// Asumimos que tu equip no guarda si está lleno.
		delete m5; 
	}

	return (0);
}