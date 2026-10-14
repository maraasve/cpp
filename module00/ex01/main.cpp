/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:50:08 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:17 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string	get_input(std::string msg, int	allow_empty)
{
	std::string	str;

	while (true)
	{
		std::cout << msg;
		std::getline(std::cin, str);
		if (std::cin.eof())
			return ("");
		str = trim(str);
		if (str.empty() && !allow_empty)
			std::cout << "Field cannot be empty." << std::endl;
		else
			return (str);
	}
}

int	prompt_contact_info(Phonebook *phonebook)
{
	std::string	str;

	str = get_input("Enter first name: ", 0);
	if (str.empty())
		return (0);
	phonebook->contacts[phonebook->index % 8].set_first_name(str);
	str = get_input("Enter last name: ", 0);
	if (str.empty())
		return (0);
	phonebook->contacts[phonebook->index % 8].set_last_name(str);
	str = get_input("Enter nickname: ", 0);
	if (str.empty())
		return (0);
	phonebook->contacts[phonebook->index% 8].set_nickname(str);
	while (1)
	{
		str = get_input("Enter phonenumber: ", 0);
		if (str.empty())
			return (0);
		if (is_numeric_str(str))
			break;
		std::cout << "Phonenumber has to be numeric." << std::endl;
	}
	phonebook->contacts[phonebook->index % 8].set_phonenumber(str);
	str = get_input("Enter darkest secret: ", 0);
	if (str.empty())
		return (0);
	phonebook->contacts[phonebook->index % 8].set_darkest_secret(str);
	phonebook->index++;
	return (1);
}

int	add(Phonebook *phonebook)
{
	std::string	str;

	if (phonebook->index > 7)
	{
		do {
			std::cout << "Warning, contact " << phonebook->contacts[phonebook->index % 8].get_first_name() \
				<< " will be overwritten.";
			std::cout << " Do you wish to proceed? y/n" << std::endl;
			std::getline(std::cin, str);
		} while (str != "y" && str != "n");
		if (str != "y")
			return (1);
	}
	if (!prompt_contact_info(phonebook))
		return (0);
	return (1);
}

void	search(Phonebook *phonebook)
{
	int			num;
	std::string	input;
	
	if (!phonebook->index)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < phonebook->index && i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << std::right << format_field(phonebook->contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << format_field(phonebook->contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << std::right << format_field(phonebook->contacts[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "                                             " << std::endl;

	std::cout << "Enter the index of the entry to display: ";
	std::getline(std::cin, input);

	try 
	{
		num = std::stoi(input);
		if (num < 0 || num > 8)
		{
			std::cout << "Input number is out of range." << std::endl;
			return ;
		}
	} 
	catch (const std::invalid_argument& e) 
	{
		std::cout << "Invalid input." << std::endl;
		return ;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Input number is out of range." << std::endl;
		return;
	}
	phonebook->contacts[num % 8].print_contact();
}

int	main(void)
{
	Phonebook 	phonebook;
	std::string	str;

	std::cout << "Use commands ADD, SEARCH and EXIT to navigate the phonebook." << std::endl;
	while (str != "EXIT" && str != "exit")
	{
		str = get_input("Enter a command: ", 1);
		str = to_upper(str);
		if (str == "ADD")
		{
			if (!add(&phonebook))
				return (0);
		}
		else if (str == "SEARCH")
			search(&phonebook);
		else if (std::cin.eof())
			return (0);
	}
}
