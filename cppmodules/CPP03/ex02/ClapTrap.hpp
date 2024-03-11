#pragma once

#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackPoints;
        ClapTrap();
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ClapTrap& operator=(ClapTrap const &copy);
        ~ClapTrap(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);        
};