/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:34:06 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/12 17:01:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog()
{
	_Type = "Dog";
	_Brain = new Brain();
	std::cout << MAGENTA << "Dog default constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << MAGENTA << "Dog destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
	_Type = other._Type;
	_Brain = new Brain(*other._Brain);
	std::cout << MAGENTA << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_Type = other._Type;
		_Brain = new Brain(*other._Brain);
	}
	std::cout << MAGENTA << "Dog copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << MAGENTA << "WOOF WOOF" << RESET << std::endl;
}
