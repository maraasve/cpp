/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:38:51 by marieke           #+#    #+#             */
/*   Updated: 2025/03/10 12:51:14 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_gateKeeping = false;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	_Name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_gateKeeping = false;
	std::cout << "ScavTrap " << _Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	_Name = other._Name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	_gateKeeping = other._gateKeeping;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
		_gateKeeping = other._gateKeeping;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_EnergyPoints > 0 && _HitPoints > 0)
	{
		_EnergyPoints--;
		std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _Name << " either doesn't have enough energy points or is already dead..." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_HitPoints > 0 && !_gateKeeping)
	{
		_gateKeeping = true;
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	}
	else if (_HitPoints > 0 && _gateKeeping)
		std::cout << "ScavTrap was already in Gate keeper mode and there's no way to stop it" << std::endl;
	else
		std::cout << "ScavTrap cannot enter Gate keeper mode, because it's dead" << std::endl;
}