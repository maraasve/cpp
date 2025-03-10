/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:33:42 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:43:00 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <WrongCat.hpp>

WrongCat::WrongCat()
{
	_Type = "WrongCat";
	std::cout << BLUE << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BLUE << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	_Type = other._Type;
	std::cout << BLUE << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		_Type = other._Type;
	std::cout << BLUE << "WrongCat copy assignment operator called" << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound()
{
	std::cout << BLUE << "MIAAAUW" << RESET << std::endl;
}