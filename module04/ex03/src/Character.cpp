/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:38:28 by marieke           #+#    #+#             */
/*   Updated: 2025/03/17 16:14:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _Name("Anonymous")
{
	for (int i = 0; i < inventorySize; i++)
		_Inventory[i] = nullptr;
}

Character::Character(const std::string &name): _Name(name)
{
	for (int i = 0; i < inventorySize; i++)
		_Inventory[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < static_cast<int>(_UnequipedMateria.size()); i++)
		delete _UnequipedMateria[i];
	_UnequipedMateria.clear();
	for (int i = 0; i < inventorySize; i++)
	{
		delete _Inventory[i];
		_Inventory[i] = nullptr;
	}
}

Character::Character(const Character &other)
{
	_Name = other._Name;
	for (int i = 0; i < inventorySize; i++)
	{
		if (other._Inventory[i])
			_Inventory[i] = other._Inventory[i]->clone();
		else
			_Inventory[i] = nullptr;
	}
}

Character&	Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_Name = other._Name;
		for (int i = 0; i < inventorySize; i++)
		{
			delete _Inventory[i];
			_Inventory[i] = nullptr;
			if (other._Inventory[i])
				_Inventory[i] = other._Inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (_Name);
}

void	Character::equip(AMateria *m)
{	
	if (!m)
	{
		std::cout	<< RED << "Invalid materia" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < inventorySize; i++)
	{
		if (!_Inventory[i])
		{
			_Inventory[i] = m;
			std::cout	<< MAGENTA << "Character " << _Name << " equips " 
						<< m->getType() << RESET << std::endl;
			return ;
		}
	}
	std::cout	<< RED << "Character " << _Name << " cannot equip "
				<< m->getType() << " due to full inventory" 
				<< RESET << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < inventorySize && _Inventory[idx])
	{	
		std::cout	<< MAGENTA << "Character " << _Name << " unequips " 
						<< _Inventory[idx]->getType() << RESET << std::endl;
		_UnequipedMateria.push_back(_Inventory[idx]);
		_Inventory[idx] = nullptr;
	}
	else
		std::cout << RED << "Incorrect index" << RESET << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < inventorySize && _Inventory[idx])
		_Inventory[idx]->use(target);
	else
		std::cout << RED << "Incorrect index" << RESET << std::endl;
}