/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:55:44 by marieke           #+#    #+#             */
/*   Updated: 2025/03/17 16:06:12 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <AMateria.hpp>
# include <ICharacter.hpp>
# include <vector>
# include <Ice.hpp>

# define inventorySize 4
# define MAGENTA "\033[35m"
# define RED "\033[31m"
# define RESET "\033[0m"

class Character: public ICharacter
{
	private:
		std::string				_Name;
		AMateria				*_Inventory[inventorySize];
		std::vector<AMateria*>	_UnequipedMateria;

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		Character&	operator=(const Character &other);
		~Character();

		std::string const	&getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter &target) override;
};

#endif
