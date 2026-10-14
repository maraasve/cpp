/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:04:43 by maraasve          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:22 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_H
# define PHONEBOOK_UTILS_H

#include "phonebook.h"

std::string	trim(std::string str);
std::string	format_field(std::string str);
std::string to_upper(std::string& str);
bool		is_numeric_str(std::string &str);

#endif