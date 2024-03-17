/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:16:40 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:54:10 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap me( "me" );

    me.whoAmI();

    me.attack( "the air" );
    me.takeDamage( 10 );
    me.beRepaired( 10 );
    me.guardGate();
    me.highFiveGuys();

    return (1);
}