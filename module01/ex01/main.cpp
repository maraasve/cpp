/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:24:26 by marieke           #+#    #+#             */
/*   Updated: 2024/09/06 11:51:17 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int		N = 10;
	Zombie *horde = zombieHorde(N, "Bernie");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
