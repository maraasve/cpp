/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:14:14 by marieke           #+#    #+#             */
/*   Updated: 2025/03/05 17:07:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Bob("Bob");

	Bob.attack("Henry");
	Bob.takeDamage(7);
	Bob.beRepaired(2);
	Bob.takeDamage(20);
	Bob.takeDamage(1);
}