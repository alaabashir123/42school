/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:00:55 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 15:21:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <exception>

class notFound : public std::exception
{
    virtual const char * what() const throw()  
    {  
        return "Value is not found";
    }  
};

template <typename T>
void easyfind(T& array, int x)
{
    if (std::find(array.begin(), array.end(), x) != array.end())
        std::cout << x << " is found" << std::endl;
    else
        throw notFound();
}
#endif