/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:26 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 17:25:15 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"

int main ( void ) 
{
    std::cout << "a(0, 0), b(2, 0), c(0, 2)" << std::endl;
    if ( bsp( Point(0, 0), Point(2, 0), Point(0, 2), Point(10, 10) ) == true ) {
        std::cout << "Point (10, 10) is in the triangle" << std::endl;
    } else {
        std::cout << "Point (10, 10) is not in the triangle" << std::endl;
    }
    
    if ( bsp( Point(0, 0), Point(2, 0), Point(0, 2), Point(1, 1) ) == true ) {
        std::cout << "Point (1, 1) is in the triangle" << std::endl;
    } else {
        std::cout << "Point (1, 1) is not in the triangle" << std::endl;
    }
    return 0;
}