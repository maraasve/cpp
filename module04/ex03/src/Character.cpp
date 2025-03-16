/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:38:28 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 14:52:02 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::~Character()
{
}

Character::Character(const Character &other)
{
	_Name = other._Name;
		//copy inventory check previous assignment
}

Character&	Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_Name = other._Name;
		//copy inventory check previous assignment
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_Name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < inventorySize; i++)
	{
		if (!_Inventory[i])
		{
			_Inventory[i] = m;
			std::cout	<< "Character " << _Name << " equips " 
						<< m->getType() << std::endl;
			return ;
		}
	}
	std::cout	<< "Character " << _Name << " cannot equip "
				<< m->getType() << " due to full inventory" 
				<< std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < inventorySize)
	{
		
	}
}