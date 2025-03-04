/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:21:56 by marieke           #+#    #+#             */
/*   Updated: 2025/03/04 13:39:43 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_Name;

	public:
		DiamondTrap(std::string name);
		//DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		//DiamondTrap	&operator=(const DiamondTrap &other);
		using ScavTrap::attack;
		void	whoAmI();
};

#endif