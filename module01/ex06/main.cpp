/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/19 23:15:03 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int	main(int argc, char *argv[])
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << "Usage: ./Harlfilter <complaint>";
		return (1);
	}
	harl.complain(argv[1]);
}
