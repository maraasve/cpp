/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:26:53 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 16:35:35 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <Cat.hpp>
#include <Animal.hpp>

#include <WrongAnimal.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

#include <limits>

#define animalNum 4

int	main(void)
{
	Animal	*listOfAnimals[animalNum];
	std::cout << "INITIALISING ARRAY:" << std::endl;
	for (int i = 0; i < animalNum; i++)
	{
		if(i < animalNum / 2)
			listOfAnimals[i] = new Dog();
		else
			listOfAnimals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "DELETING ARRAY:" << std::endl;

	for (int i = 0; i < animalNum; i++)
	{
		delete listOfAnimals[i];
		std::cout << std::endl;
	}
}
