/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:57:36 by maraasve          #+#    #+#             */
/*   Updated: 2025/03/17 16:13:10 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < materiasSize; i++)
		_Materias[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < materiasSize; i++)
	{
		delete _Materias[i];
		_Materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < materiasSize; i++)
	{
		if (other._Materias[i])
			_Materias[i] = other._Materias[i]->clone();
		else
			_Materias[i] = nullptr;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < materiasSize; i++)
		{
			delete _Materias[i];
			_Materias[i] = nullptr;
			if (other._Materias[i])
				_Materias[i] = other._Materias[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout	<< RED << "Invalid material" << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < materiasSize; i++)
	{
		if (!_Materias[i])
		{
			_Materias[i] = m;
			std::cout	<< YELLOW << "MateriaSource learned " << _Materias[i]->getType()
						<< RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "MateriaSource storage is full, materia will be deleted" << RESET << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < materiasSize; i++)
	{
		if (_Materias[i] && type == _Materias[i]->getType())
		{
			std::cout	<< YELLOW << "MateriaSource succesfully created a " << type 
						<< " materia" << RESET << std::endl;
			return (_Materias[i]->clone());
		}
	}
	std::cout << RED << "Materia " << type << " unknown" << RESET << std::endl;
	return (nullptr);
}