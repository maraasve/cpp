/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:32 by marieke           #+#    #+#             */
/*   Updated: 2024/09/17 12:39:00 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkest_secret;
		std::string	get_phonenumber(void) const;
		std::string	get_darkest_secret(void) const;

	public:
		Contact();
		~Contact();
		
		std::string	get_nickname(void) const;
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_phonenumber(std::string str);
		void		set_darkest_secret(std::string str);
		void		print_contact(void);
};

#endif