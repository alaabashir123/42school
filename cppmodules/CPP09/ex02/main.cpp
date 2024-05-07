/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:23:11 by abashir           #+#    #+#             */
/*   Updated: 2024/05/07 13:03:23 by abashir          ###   ########.fr       */
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
        clock_t start_vec = clock();
        std::vector<int> vec;
        readInput(argv, ac, vec);
        if (vec.empty())
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        std::cout << "Before : ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        mergeInsertionSort(vec, 0, vec.size() - 1, 5);
        std::cout << "After :  ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        clock_t end_vec = clock();
        double elapsedTime_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

        clock_t start_lst = clock();
        std::list<int> lst;
        readInput(argv, ac, lst);
            if (lst.empty())
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        mergeInsertionSort(lst, 0, lst.size() - 1, 5);
        std::cout << "After :  ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << " ";
        clock_t end_lst = clock();
        double elapsedTime_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;
        std::cout << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << elapsedTime_vec << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::list   : " << elapsedTime_lst << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}