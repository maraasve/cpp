/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:14:06 by marieke           #+#    #+#             */
/*   Updated: 2025/03/10 12:51:31 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		const static int	_defaultHP = 100;
		const static int	_defaultEP = 100;
		const static int	_defaultAD = 30;

	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &other);
		
		void		highFiveGuys();
};

#endif