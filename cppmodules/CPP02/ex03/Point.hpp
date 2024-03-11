/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:40 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 16:56:32 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(Point const &copy);
        Point& operator=(Point const &rhs);
        ~Point(void);
        Fixed getX() const;
        Fixed getY() const;
};
