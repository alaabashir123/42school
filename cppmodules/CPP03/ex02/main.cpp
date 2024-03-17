/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:07:14 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:30:42 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
    FragTrap me( "me" );
    FragTrap someone( me );

    me.attack( "the stone" );
    me.takeDamage( 90 );
    me.beRepaired( 10 );
    me.highFiveGuys();

    return (1);
}