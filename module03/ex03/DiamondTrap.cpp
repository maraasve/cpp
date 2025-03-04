/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:00 by marieke           #+#    #+#             */
/*   Updated: 2025/03/04 13:38:41 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	_Name = name;
	_HitPoints = FragTrap::_HitPoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
}

void	DiamondTrap::whoAmI()
{
	std::cout <<  "DiamondTrap name = " << _Name << ". And its ClapTrap name = " << ClapTrap::_Name << std::endl; 
}
