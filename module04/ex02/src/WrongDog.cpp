/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:34:06 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:43:04 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WrongDog.hpp>

WrongDog::WrongDog()
{
	_Type = "WrongDog";
	std::cout << MAGENTA << "WrongDog default constructor called" << RESET << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << MAGENTA << "WrongDog destructor called" << RESET << std::endl;
}

WrongDog::WrongDog(const WrongDog &other)
{
	_Type = other._Type;
	std::cout << MAGENTA << "WrongDog copy constructor called" << RESET << std::endl;
}

WrongDog&	WrongDog::operator=(const WrongDog &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << MAGENTA << "WrongDog copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	WrongDog::makeSound()
{
	std::cout << MAGENTA << "WOOF WOOF" << RESET << std::endl;
}
