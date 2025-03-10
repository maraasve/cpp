/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:14:14 by marieke           #+#    #+#             */
/*   Updated: 2025/03/10 12:53:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Steward("Steward");

	Steward.attack("Bob");
	Steward.guardGate();
	Steward.takeDamage(50);
	Steward.takeDamage(40);
	Steward.takeDamage(10);
}
