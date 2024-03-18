/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:10:31 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:31:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unknown")
{
    for (int i = 0; i < 4; i++)
    {
        _inventroy[i] = NULL;
        _unused[i] = NULL;
    }
    
    // std::cout << "Character Default Constructor is called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        _inventroy[i] = NULL;
        _unused[i] = NULL;        
    }
    // std::cout << "Character " << name << " Constructor is called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventroy[i])
            delete _inventroy[i];
        if (_unused[i])
            delete _unused[i];        
    }
    // std::cout << "Character Destructor is called" << std::endl;   
}

Character::Character(const Character &copy)
{
    // std::cout << "Character Copy Constructor is called" << std::endl;
	_name = copy._name;
	for (int i = 0; i < 4; i++)
    {
		_inventroy[i] = NULL;
        _unused[i] = NULL;
    }
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventroy[i])
		{
			_inventroy[i] = copy._inventroy[i]->clone();
            _unused[i] = copy._unused[i]->clone();
		}
	}
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
	    {
		    if (_inventroy[i])
		    {
			    delete _inventroy[i];
			    _inventroy[i] = NULL;
		    }
            if (_unused[i])
		    {
			    delete _unused[i];
			    _unused[i] = NULL;
		    }
	    }
        for (int i = 0; i < 4; i++)
        {
            if (rhs._inventroy[i])
                _inventroy[i] = rhs._inventroy[i]->clone();
            if (rhs._unused[i])
                _unused[i] = rhs._unused[i]->clone();           
        }
    }
    return (*this);
}      

std::string const & Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Materia is NULL!" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_inventroy[i] == m)
        {
            std::cout << "You have already stored this materia!" << std::endl;
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!_inventroy[i])
        {
            _inventroy[i] = m;
            // std::cout << this->_name << " is equiped with " << m->getType() << " at index " << i << std::endl;  
            return;
        } 
    }
    std::cout << "Inventory is full!" << std::endl;
    
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (_unused[i] == NULL)
            {
                _unused[i] = _inventroy[idx];
                _inventroy[idx] = NULL;
                std::cout << "Unequiped from index " << idx << std::endl;
                return;
            }
        }
        delete _unused[0];
        for (size_t i = 1; i < 4; i++)
            _unused[i - 1] = _unused[i];
        _unused[3] = NULL;
        _unused[3] = _inventroy[idx];
        _inventroy[idx] = NULL;
        std::cout << "Unequiped from index " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Invalid Index" << std::endl;
        return;
    }
    if (_inventroy[idx])
        _inventroy[idx]->use(target);
    else
        std::cout << "AMateria is not found at index " << idx << std::endl;
}