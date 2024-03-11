/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:25 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 16:37:39 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0)
{
}

Fixed::Fixed(Fixed const &copy)
{
    *this = copy;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
    if (this != &rhs)
        this->_fixedPointNumber = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
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
}

Fixed::Fixed(const float f) : _fixedPointNumber(roundf(f *( 1 << _fractBits)))
{
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

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_fixedPointNumber > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_fixedPointNumber < rhs.getRawBits());    
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_fixedPointNumber >= rhs.getRawBits());    
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_fixedPointNumber <= rhs.getRawBits());    
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_fixedPointNumber == rhs.getRawBits());    
}
bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_fixedPointNumber != rhs.getRawBits());    
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    this->_fixedPointNumber += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_fixedPointNumber += 1;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->_fixedPointNumber -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_fixedPointNumber -= 1;
    return (temp);
}

const Fixed& Fixed::min(const Fixed &a,const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}   
    
const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}