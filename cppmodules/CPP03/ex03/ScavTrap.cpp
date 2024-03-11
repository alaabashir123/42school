#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor is called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackPoints = 20;
}
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor is called" << std::endl;

}
ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
    *this = copy;
}
ScavTrap& ScavTrap::operator=(ScavTrap const &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_attackPoints = rhs._attackPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
    {
        std::cout << "No energy/hit points left" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target;
    std::cout << ", causing " << this->_attackPoints << " points of damage" << std::endl;
    this->_energyPoints -= 1;    
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}