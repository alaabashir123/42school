/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:32 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 16:38:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPointNumber;
        static const int _fractBits = 8;
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed(Fixed const &copy);
        Fixed& operator=(Fixed const &rhs);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);

        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;

        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static const Fixed& min(const Fixed& a,const Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);        
        static const Fixed& max(const Fixed& a,const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b); 
};

std::ostream& operator<<(std::ostream &o, Fixed const &rhs);
