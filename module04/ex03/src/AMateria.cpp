/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:20:03 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 13:52:27 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _Type("empty")
{
}

AMateria::AMateria(std::string const &type): _Type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &other): _Type(other._Type)
{
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		_Type = other._Type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (_Type);
}
