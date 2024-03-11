#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackPoints = 30;
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
        this->_attackPoints = rhs._attackPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_hitPoints = rhs._hitPoints;
    }
    return (*this);
}
void FragTrap::highFiveGuys(void)
{
    std::cout << "High fives request" << std::endl;
}