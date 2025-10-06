/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:22:42 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 16:17:05 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AMateria.hpp>
#include <Character.hpp>
#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

int	main(void)
{
	{	
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("test");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	
	//testing materialsource storage
	{
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice()); //storage will be full from here on
		src->learnMateria(new Cure());
		delete src;
	}
	std::cout << std::endl;

	//testing equip storage and unequip
	{
		ICharacter *bob = new Character("Bob");
		bob->equip(new Ice());
		bob->equip(new Ice());
		bob->equip(new Cure());
		bob->equip(new Ice());
		bob->equip(new Cure());
		std::cout << std::endl;

		bob->unequip(4);
		bob->unequip(1);
		bob->unequip(3);
		std::cout << std::endl;

		bob->equip(new Ice());
		bob->equip(new Cure());
		delete bob;
	}
	return 0;
}