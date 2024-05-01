/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:23:11 by abashir           #+#    #+#             */
/*   Updated: 2024/05/01 14:20:38 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try
    {
        checkInput(argv[1]);
        std::list<int> lst;
        std::vector<int> vec;
        readInput(argv[1], lst, vec);
        std::cout << "Before : ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        mergeInsertionSort(vec, 0, vec.size() - 1, 5);
        mergeInsertionSort(lst, 0, lst.size() - 1, 5);
        std::cout << "After :  ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        std::cout << "After :  ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}