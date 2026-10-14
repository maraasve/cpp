/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:30:22 by marieke           #+#    #+#             */
/*   Updated: 2024/09/06 17:38:42 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << _name << " created with ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << _name << " destroyed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
