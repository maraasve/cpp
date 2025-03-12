/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:26:53 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/12 17:23:08 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <Cat.hpp>
#include <Animal.hpp>

#include <WrongAnimal.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

#include <limits>

#define animalNum 11

int	main(void)
{
	Animal	*listOfAnimals[animalNum];

	for (int i = 0; i < animalNum; i++)
	{
		if(i < animalNum / 2)
			listOfAnimals[i] = new Dog();
		else
			listOfAnimals[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < animalNum; i++)
	{
		delete listOfAnimals[i];
		std::cout << std::endl;
	}
	Dog Boeffie;
	std::cout << std::endl;
	Dog Nemo(Boeffie);
	std::cout << std::endl;
}
