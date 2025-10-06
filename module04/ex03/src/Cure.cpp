/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:38 by marieke           #+#    #+#             */
/*   Updated: 2025/03/17 15:53:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
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
	std::cout	<< GREEN << "* heals " << target.getName()
				<< "'s wounds *" << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}