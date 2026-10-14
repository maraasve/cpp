/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:05:08 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:11 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string to_upper(std::string& str)
{
    std::string result = str;
    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

std::string	trim(std::string str)
{
	int	start;
	int	end;

	start = str.find_first_not_of(" \t\n\v\f\r");
	if ((const unsigned long)start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t\n\v\f\r");
	return (str.substr(start, end - start + 1));
}

std::string	format_field(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool	is_numeric_str(std::string &str)
{
	if (str.empty()) 
		return (false);
	for (char &c : str)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return (false);
	}
	return (true);
}
