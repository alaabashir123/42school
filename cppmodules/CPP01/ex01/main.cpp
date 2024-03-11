/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:20:15 by abashir           #+#    #+#             */
/*   Updated: 2024/02/15 13:04:29 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    int size = 5;
    if (size < 0)
        return (1);
    Zombie *test = zombieHorde(size, "Zombie A");
    for (int i = 0; i < size; i++)
        test[i].announce();

    delete[] test;
}
