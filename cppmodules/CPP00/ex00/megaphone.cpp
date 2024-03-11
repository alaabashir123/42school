/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:32:07 by abashir           #+#    #+#             */
/*   Updated: 2024/02/07 12:54:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                av[i][j] = std::toupper(av[i][j]);
                j++;
            }
            std::cout << av[i];
            i++;
        }
        std::cout << std::endl;
    }
}

