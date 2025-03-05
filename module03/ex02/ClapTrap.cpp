/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:31:13 by marieke           #+#    #+#             */
/*   Updated: 2025/03/05 16:29:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name("Anonymous"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << _Name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _Name(other._Name), _HitPoints(other._HitPoints), _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
		_EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << _Name << " either doesn't have enough energy points or is already dead..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints > 0)
	{
		std::cout << "ClapTrap loses " << amount << " hit points." << std::endl;
		if (_HitPoints > (int)amount)
			_HitPoints -= amount;
		else
		{
			std::cout << "ClapTrap " << _Name << " died R.I.P" << std::endl;
			_HitPoints = 0;
		}
	}
	else
		std::cout << "ClapTrap " << _Name << " is already dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		std::cout << "ClapTrap repairs itself with " << amount << " hit points." << std::endl;
		_HitPoints += amount;
		_EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << _Name << " either doesn't have enough energy points or is already dead..." << std::endl;
}