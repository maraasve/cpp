/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:33:35 by marieke           #+#    #+#             */
/*   Updated: 2024/09/17 12:42:33 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.h"
# include "strings.h"
# include <iomanip>

class Phonebook 
{
	public:
		Contact contacts[8];
		int		index;
		Phonebook();
		~Phonebook();
		Contact get_contact(int index);
};

#endif