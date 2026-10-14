/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:54:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/19 16:36:02 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	replace(char *argv[], std::string buffer)
{
	std::ofstream	outfile;
	std::string		old_str;
	std::string		new_str;
	size_t			pos;
	size_t			last_pos;
	
	outfile.open((std::string(argv[1])) + ".replace");
	if (!outfile.is_open())
	{
		std::cout << "Error opening outfile" << std::endl;
		return ;
	}
	old_str = argv[2];
	new_str = argv[3];
	pos = 0;
	last_pos = 0;
	while((pos = buffer.find(old_str, last_pos)) != std::string::npos)
	{
		outfile << buffer.substr(last_pos, pos - last_pos);
		outfile << new_str;
		last_pos = pos + old_str.length();
	}
	outfile << buffer.substr(last_pos);
	outfile.close();
}

int	main(int argc, char	*argv[])
{
	std::ifstream	infile;
	std::string		buffer;
	char			c;

	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <str1> <str2>" << std::endl;
		return (0);
	}
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Error opening infile" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
        buffer += c;
	infile.close();
	replace(argv, buffer);
	return (0);
}
