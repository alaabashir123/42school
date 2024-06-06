/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:41:18 by abashir           #+#    #+#             */
/*   Updated: 2024/06/06 13:43:04 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **argv)
{
    if (ac == 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try
    {
        checkInput(argv, ac);
        sortVector(argv, ac);
        sortList(argv, ac);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}