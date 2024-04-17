/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:04:31 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 12:22:50 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void f(T& x)
{
    std::cout << x << std::endl;
}
template <typename T>
void iter(T* array, size_t size, void (*f)(T& x))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}
#endif