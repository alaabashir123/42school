#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(FragTrap const &copy);
        FragTrap& operator=(FragTrap const &copy);
        void highFiveGuys(void);
    private:
        FragTrap();
        
};