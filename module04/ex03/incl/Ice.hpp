/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:32 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 13:57:11 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <AMateria.hpp>

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);
		~Ice();

		void	use(ICharacter &target) override;
};

#endif
