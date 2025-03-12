/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:40 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:54 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal()
{
	_Type = "WrongAnimal";
	std::cout << RED << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	_Type = other._Type;
	std::cout << RED << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << RED << "WrongAnimal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound()
{
	std::cout << RED << "GENARIC WrongAnimal SOUND" << RESET << std::endl;
}

std::string	WrongAnimal::getType()
{
	return (_Type);
}