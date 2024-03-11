#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "Diamond Constructor is called" << std::endl;
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackPoints = FragTrap::_attackPoints;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond Destructor is called" << std::endl;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl; 
}
