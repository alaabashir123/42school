/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:00:18 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 11:56:36 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap me( "me" );
    ScavTrap someone( me );

    me.attack( "the stone" );
    me.takeDamage( 10 );
    me.beRepaired( 10 );
    me.guardGate();

    return (1);
}