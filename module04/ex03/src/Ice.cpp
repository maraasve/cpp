/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:40 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 13:53:47 by marieke          ###   ########.fr       */
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
	std::cout	<< "* heals" 
				<< target.getName()
				<< "'s wounds *"
				<< std::endl;
}