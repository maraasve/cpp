/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:55:44 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 14:42:49 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <AMateria.hpp>
# include <ICharacter.hpp>

# define inventorySize 4

class Character: public ICharacter
{
	private:
		std::string	_Name;
		AMateria	*_Inventory[inventorySize];

	public:
		Character();
		Character(const Character &other);
		Character&	operator=(const Character &other);
		~Character();

		std::string const	&getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter &target);
};

#endif
