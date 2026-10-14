/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:37 by marieke           #+#    #+#             */
/*   Updated: 2024/09/17 12:41:29 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Phonebook::Phonebook(void)
{
	index = 0;
	std::cout << "Created an empty phonebook for up to 8 contacts." << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook deleted." << std::endl;
}

Contact Phonebook::get_contact(int index)
{
	return (contacts[index % 8]);
}
