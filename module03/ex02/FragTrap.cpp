/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:14:01 by marieke           #+#    #+#             */
/*   Updated: 2025/03/05 17:04:30 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_Name = name;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	_Name = other._Name;
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	if (_HitPoints > 0)
		std::cout << "FragTrap requests a high Five!" << std::endl;
	else
		std::cout << "FragTrap cannot high five anymore, because it's dead" << std::endl;
}
