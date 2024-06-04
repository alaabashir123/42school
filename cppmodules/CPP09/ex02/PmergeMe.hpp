/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:20:45 by abashir           #+#    #+#             */
/*   Updated: 2024/06/02 17:45:03 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <exception>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

class invalidInput : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Error: Invalid input";
    }   
};

bool checkInt(std::string input);
void checkInput(char **argv, int ac);
void readInput(char **argv, int ac, std::list<int> &lst);
void readInput(char **argv, int ac, std::vector<int> &vec);
std::vector<int> mergeInsertionSort(std::vector<int> &vec);
void mergeInsertionSort(std::list<int> &lst, size_t left, size_t right, size_t k);
void print(std::vector<int> vec);

#endif