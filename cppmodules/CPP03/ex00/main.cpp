#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Knife");

    for (int i = 0; i < 9; i++)
        clap.takeDamage(1);
    clap.beRepaired(10);
    clap.attack("enemy");
    return (1);
}