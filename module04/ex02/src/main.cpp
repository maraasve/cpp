/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:26:53 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 16:20:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>
#include <Cat.hpp>
#include <AAnimal.hpp>

#include <WrongAnimal.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

#include <limits>

#define animalNum 11

int	main(void)
{
	//AAnimal	test;
	
	Dog Boeffie;
	std::cout << std::endl;
	Dog Nemo(Boeffie);
	std::cout << std::endl;
}
