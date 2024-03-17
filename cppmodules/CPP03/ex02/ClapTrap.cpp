/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:06:56 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:30:07 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor is called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Constructor is called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "ClapTrap Copy constructor is called" << std::endl;
    *this = copy;
}
ClapTrap& ClapTrap::operator=(ClapTrap const &rhs)
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
ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor is called" << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap no energy/hit points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackDamage << " points of damage" << std::endl;
    this->_energyPoints -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    int temp = this->_hitPoints - amount;
    if (temp < 0)
    {
        std::cout << "ClapTrap has no Health points left" << std::endl;
        this->_hitPoints = 0;
        return;
    }
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " took damage";
    std::cout << ", causing " << amount << " points of damage" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap has no energy/hit points left" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " has been repaired by " << amount;
    std::cout << ". Your new hit points is " << this->_hitPoints << std::endl;
}