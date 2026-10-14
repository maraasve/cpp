/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:24:07 by marieke           #+#    #+#             */
/*   Updated: 2024/09/13 16:52:18 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout << "HumanB " << _name << " created with no weapon " << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << _name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}
