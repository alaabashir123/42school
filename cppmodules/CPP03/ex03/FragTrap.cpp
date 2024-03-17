/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:16:32 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:54:37 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default Constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor is called" << std::endl;
}
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor is called" << std::endl;

}
FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor is called" << std::endl;
    *this = copy;
}
FragTrap& FragTrap::operator=(FragTrap const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackDamage = rhs._attackDamage;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}
void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap made a High fives request" << std::endl;
}