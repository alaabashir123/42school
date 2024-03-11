/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:08:07 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 15:23:04 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *testZombieA;

    testZombieA = newZombie("Zombie A");
    testZombieA->announce();
    delete testZombieA;
    randomChump("Zombie B");
}