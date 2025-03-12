/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:27:36 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/10 17:13:39 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define RED "\033[31m"
# define RESET "\033[0m"

class AAnimal
{
	protected:
		std::string	_Type;

	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void	makeSound() = 0;
		
		std::string	getType();
};

#endif
