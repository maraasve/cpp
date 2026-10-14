/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:03:46 by marieke           #+#    #+#             */
/*   Updated: 2024/09/16 14:24:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_first_name(void) const
{
	return (_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (_nickname);
}

std::string	Contact::get_phonenumber(void) const
{
	return (_phonenumber);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (_darkest_secret);
}

void	Contact::set_first_name(std::string str)
{
	_first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	_last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	_nickname = str;
}

void	Contact::set_phonenumber(std::string str)
{
	_phonenumber = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	_darkest_secret = str;
}

void	Contact::print_contact(void)
{
	if (!get_first_name().size())
	{
		std::cout << "Failed to fetch contact info." << std::endl;
		return ;
	}
	std::cout << "First name: " << get_first_name() << std::endl;
	std::cout << "Last name: " << get_last_name() << std::endl;
	std::cout << "Nickname: " << get_nickname() << std::endl;
	std::cout << "Phonenumber: " << get_phonenumber() << std::endl;
	std::cout << "Darkest secret: " << get_darkest_secret() << std::endl;
}
