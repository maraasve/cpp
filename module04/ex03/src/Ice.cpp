/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:40 by marieke           #+#    #+#             */
/*   Updated: 2025/03/17 15:08:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_Type = "ice";
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &other)
{
	_Type = other._Type;
}

Ice& Ice::operator=(const Ice &other)
{
	if (this != &other)
		_Type = other._Type;
	return (*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout	<< BLUE << "* shoots an ice bolt at" << target.getName() 
				<< "*" << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}