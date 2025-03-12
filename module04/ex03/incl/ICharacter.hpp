/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:47 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/12 17:23:52 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter 
{
	public:
		ICharacter();
		ICharacter(const ICharacter &other);
		ICharacter& operator=(const ICharacter &other);
		~ICharacter();

};

#endif
