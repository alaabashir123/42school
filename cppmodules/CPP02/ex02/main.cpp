/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:37 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 17:34:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed c( Fixed( 5 ) + Fixed( 2 ) );
std::cout << "sum of 5 and 2 is: " << c << std::endl;
c = Fixed( 5 ) - Fixed( 2 );
std::cout << "sucstract of 5 and 2 is: " << c << std::endl;
c = Fixed( 5 ) * Fixed( 2 );
std::cout << "multiplication of 5 and 2 is: " << c << std::endl;
c = Fixed( 5 ) / Fixed( 2 );
std::cout << "division of 5 and 2 is: " << c << std::endl;
std::cout << "-------------------------------------" << std::endl;

std::cout << "a is " << a << " c is " << c << std::endl;
if (a > c)
    std::cout << "a is bigger than c" << std::endl;
else
    std::cout << "a is smaller than c" << std::endl;
if (a == c)
    std::cout << "a is equal to c" << std::endl;
else
    std::cout << "a is not equal to c" << std::endl;
std::cout << "-------------------------------------" << std::endl;

Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}