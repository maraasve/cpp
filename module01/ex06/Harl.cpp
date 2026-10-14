/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:01:18 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/19 23:22:22 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout	<< "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
				<< "ketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon"
				<< "in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas "
				<< "you started working here since last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout	<< "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*complaint[])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	switch(i){
		case(0):
			(this->*complaint[0])();
		case(1):
			(this->*complaint[1])();
		case(2):
			(this->*complaint[2])();
		case(3):
			(this->*complaint[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}