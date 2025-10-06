/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:32 by marieke           #+#    #+#             */
/*   Updated: 2025/03/17 15:35:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <AMateria.hpp>
# include <ICharacter.hpp>
# define BLUE "\033[34m"
# define RESET "\033[0m"


class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);
		~Ice();

		void		use(ICharacter &target) override;
		AMateria*	clone() const override;
};

#endif
