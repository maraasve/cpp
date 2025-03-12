/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:40 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Animal.hpp>

Animal::Animal()
{
	_Type = "Animal";
	std::cout << RED << "Animal default constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &other)
{
	_Type = other._Type;
	std::cout << RED << "Animal copy constructor called" << RESET << std::endl;
}

Animal&	Animal::operator=(const Animal &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << RED << "Animal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	Animal::makeSound()
{
	std::cout << RED << "GENARIC ANIMAL SOUND" << RESET << std::endl;
}

std::string	Animal::getType()
{
	return (_Type);
}