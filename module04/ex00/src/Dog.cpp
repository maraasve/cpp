/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:34:06 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:25 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Dog.hpp>

Dog::Dog()
{
	_Type = "Dog";
	std::cout << MAGENTA << "Dog default constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
	_Type = other._Type;
	std::cout << MAGENTA << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << MAGENTA << "Dog copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound()
{
	std::cout << MAGENTA << "WOOF WOOF" << RESET << std::endl;
}
