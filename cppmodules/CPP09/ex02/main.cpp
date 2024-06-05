/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:41:18 by abashir           #+#    #+#             */
/*   Updated: 2024/06/05 17:45:44 by abashir          ###   ########.fr       */
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
        if (vec.empty() || vec.size() == 1)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        std::cout << "Before : ";
        print(vec);
        std::vector<int> S = mergeInsertionSort(vec);
        clock_t end_vec = clock();
        
        std::cout << "After :  ";
        print(S);
        double elapsedTime_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

        clock_t start_lst = clock();
        std::list<int> lst;
        readInput(argv, ac, lst);
        if (lst.empty() || lst.size() == 1)
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
        std::list<int> S = mergeInsertionSort(lst);
        clock_t end_lst = clock();
        
        std::cout << "After :  ";
        print(S);
        double elapsedTime_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << lst.size() << " elements with std::vector : " << std::fixed << std::setprecision(7) << elapsedTime_lst << std::endl;


        
        // mergeInsertionSort(lst, 0, lst.size() - 1, 2);
        // std::cout << "After :  ";
        // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        //     std::cout << *it << " ";
        // clock_t end_lst = clock();
        // double elapsedTime_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;
        // std::cout << std::endl;
        // std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(7) << elapsedTime_vec << std::endl;

        // std::cout << "Time to process a range of " << vec.size() << " elements with std::list   : " << elapsedTime_lst << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}