/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:22:45 by abashir           #+#    #+#             */
/*   Updated: 2024/02/15 13:02:58 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
    Zombie* zomHorde = new Zombie[N];
    for (int i = 0; i < N; i++)
        zomHorde[i].setName(name);
    return zomHorde;
}