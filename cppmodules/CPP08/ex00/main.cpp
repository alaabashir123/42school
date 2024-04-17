/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:15 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 15:22:59 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::list<int> lst;
    std::vector<int> v(5, 10);

    for (int i = 0; i < 10; i++)
        lst.push_back(i);
    try
    {
        easyfind(v, 10);
        easyfind(lst, 11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
}