/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:26:53 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 16:28:58 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <Cat.hpp>
#include <Animal.hpp>

#include <WrongAnimal.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

#include <limits>

int	main(void)
{
	{
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* j = new WrongDog();
		WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the generic animal sound!
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}
}