#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap(ScavTrap const &copy);
        ScavTrap& operator=(ScavTrap const &rhs);
        void attack(const std::string& target);
        void guardGate(); 
};