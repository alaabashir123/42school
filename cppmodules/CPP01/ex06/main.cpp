/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:52:55 by abashir           #+#    #+#             */
/*   Updated: 2024/02/15 13:18:38 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }
    Harl test;
    test.harlFilter(argv[1]);
}