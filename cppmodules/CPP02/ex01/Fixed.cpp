/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:12:30 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 16:23:15 by abashir          ###   ########.fr       */
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
    return(this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNumber = raw;
}

Fixed::Fixed(const int n) : _fixedPointNumber(n << _fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixedPointNumber(roundf(f * (1 << _fractBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointNumber / (1 << this->_fractBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointNumber >> this->_fractBits);
}

std::ostream& operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}