/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:33:42 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cat.hpp>

Cat::Cat()
{
	_Type = "Cat";
	std::cout << BLUE << "Cat default constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << BLUE << "Cat destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
	_Type = other._Type;
	std::cout << BLUE << "Cat copy constructor called" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << BLUE << "Cat copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound()
{
	std::cout << BLUE << "MIAAAUW" << RESET << std::endl;
}