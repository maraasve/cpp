/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:33:45 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/12 17:15:37 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <Brain.hpp>
# include <AAnimal.hpp>

# include <iostream>

# define BLUE "\033[34m"
# define RESET "\033[0m"

class Cat: public AAnimal
{
	private:
		Brain	*_Brain;

	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();

		void	makeSound() override;
};

#endif
