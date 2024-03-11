/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:59:05 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 17:28:37 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
    private:
        int _fixedPointNumber;
        static const int _fractBits = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &copy);
        Fixed& operator=(Fixed const &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};