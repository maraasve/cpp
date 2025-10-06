/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:47 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 15:38:27 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <IMateriaSource.hpp>

# define materiasSize 4
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define RESET "\033[0m"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_Materias[materiasSize];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);
		~MateriaSource() override;

		void learnMateria(AMateria* m) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
