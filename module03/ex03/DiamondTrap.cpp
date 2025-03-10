/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:00 by marieke           #+#    #+#             */
/*   Updated: 2025/03/10 12:41:15 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Anonymous_clap_name")
{
	_Name = "Anonymous";
	std::cout << "Diamondtrap Default constructor called" << std::endl;
	_HitPoints = FragTrap::_defaultHP;
	_EnergyPoints = ScavTrap::_defaultEP;
	_AttackDamage = FragTrap::_defaultAD;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << _Name << " constructor called" << std::endl;
	_Name = name;
	_HitPoints = FragTrap::_defaultHP;
	_EnergyPoints = ScavTrap::_defaultEP;
	_AttackDamage = FragTrap::_defaultAD;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	_Name = other._Name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap  &other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout <<  "DiamondTrap name = " << _Name << ". And its ClapTrap name = " << ClapTrap::_Name << std::endl; 
}
