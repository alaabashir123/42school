/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:54 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 17:31:36 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "usuage: <expression>" << std::endl;
        return (0);
    }
    try
    {
        checkInput(argv[1]);
        calculateRPN(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}