/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:55:24 by abashir           #+#    #+#             */
/*   Updated: 2024/02/20 17:41:19 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed AB;
    Fixed AC;
    Fixed BC;
    bool neg, pos;

    AB = (point.getX() - b.getX()) * (a.getY() - b.getY()) - (a.getX() - b.getX()) * (point.getY() - b.getY());
    AC = (point.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (point.getY() - c.getY());
    BC = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (point.getY() - a.getY());

    neg = (AB < 0) || (AC < 0) || (BC < 0);
    pos = (AB > 0) || (AC > 0) || (BC > 0);

    return !(neg && pos);
}

