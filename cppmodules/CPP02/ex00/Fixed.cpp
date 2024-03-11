/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:13 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 15:59:16 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}
Fixed& Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointNumber = rhs.getRawBits();
    return (*this);
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;

}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixedPointNumber);
}
void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNumber = raw;
}