/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:59:57 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 11:36:38 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Knife");

    clap.takeDamage(9);
    clap.beRepaired(10);
    clap.attack("enemy");
    return (1);
}