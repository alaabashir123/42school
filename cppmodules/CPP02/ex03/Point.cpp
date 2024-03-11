/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:34 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 18:02:39 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) :_x(0), _y(0)
{
}

Point::Point(const float x, const float y) :_x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(Point const &copy)
{
    *this = copy;
}

Point& Point::operator=(Point const &rhs)
{
    if (this != &rhs)
    {
        const_cast<Fixed&> (this->_x) = rhs.getX();
        const_cast<Fixed&> (this->_y) = rhs.getY();
    }
    return (*this);
}

Point::~Point(void)
{

}

Fixed Point::getX() const
{
    return(this->_x);
}

Fixed Point::getY() const
{
    return(this->_y);
}

