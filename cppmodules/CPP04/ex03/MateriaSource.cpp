/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:01:39 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:31:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource Default Constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource Destructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    // std::cout << "MateriaSource Copy Constructor is called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria*m)
{
    if (!m)
    {
        std::cout << "AMateria is NULL!" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            // std::cout << "You have learnt a new materia " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "Inventroy is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] && type == _inventory[i]->getType())
        {
            // std::cout << "You have created a new materia of type " << type << std::endl;
            return (_inventory[i]->clone());
        }            
    }
    std::cout << "Materia " << type << " is unknown!" << std::endl;
    return (NULL);
}