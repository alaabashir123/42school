/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:12:38 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 16:14:23 by abashir          ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream &o, Fixed const &rhs);
