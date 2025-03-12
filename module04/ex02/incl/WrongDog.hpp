/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:34:09 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:42:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <WrongAnimal.hpp>
# include <iostream>

# define MAGENTA "\033[35m"
# define RESET "\033[0m"

class WrongDog: public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog &other);
		WrongDog& operator=(const WrongDog &other);
		~WrongDog();

		void	makeSound();
};

#endif