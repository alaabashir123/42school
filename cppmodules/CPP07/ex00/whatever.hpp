/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:47:45 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 11:54:02 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& x, T& y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

template <typename T>
T min(T x, T y)
{
    if (x < y)
        return (x);
    return (y);
}

template <typename T>
T max(T x, T y)
{
    if (x > y)
        return (x);
    return (y);
}

#endif