/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:30:36 by marieke           #+#    #+#             */
/*   Updated: 2025/03/16 13:57:16 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <AMateria.hpp>

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		~Cure();

		void	use(ICharacter &target) override;
};

#endif
