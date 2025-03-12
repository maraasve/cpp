/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:43 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/12 16:50:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << YELLOW << "Brain Default constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << YELLOW << "Brain Destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < ideaNum; i++)
		_Ideas[i] = other._Ideas[i]; 
	std::cout << YELLOW << "Brain Copy constructor called" << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < ideaNum; i++)
			_Ideas[i] = other._Ideas[i]; 
	}
	std::cout << YELLOW << "Brain Copy constructor called" << RESET << std::endl;
	return (*this);
}
