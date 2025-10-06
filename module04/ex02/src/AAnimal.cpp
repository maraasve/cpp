/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:40 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AAnimal.hpp>

AAnimal::AAnimal()
{
	_Type = "AAnimal";
	std::cout << RED << "AAnimal default constructor called" << RESET << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	_Type = other._Type;
	std::cout << RED << "AAnimal copy constructor called" << RESET << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << RED << "AAnimal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	AAnimal::makeSound()
{
	std::cout << RED << "GENARIC ANIMAL SOUND" << RESET << std::endl;
}

std::string	AAnimal::getType()
{
	return (_Type);
}