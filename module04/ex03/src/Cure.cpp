/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:38 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 13:52:45 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():
{
	_Type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &other)
{
	_Type = other._Type;
}

Cure& Cure::operator=(const Cure &other)
{
	if (this != &other)
		_Type = other._Type;
	return (*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout	<< "* shoots an ice bolt at" 
				<< target.getName() 
				<< "*" 
				<< std::endl;
}
