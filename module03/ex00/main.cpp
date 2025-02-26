/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:14:14 by marieke           #+#    #+#             */
/*   Updated: 2025/02/26 13:33:45 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Bob("Bob");

	Bob.attack("Fake ClapTrap");
	Bob.takeDamage(7);
	Bob.beRepaired(2);
	Bob.takeDamage(20);
	Bob.takeDamage(1);
}