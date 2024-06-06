/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:20:45 by abashir           #+#    #+#             */
/*   Updated: 2024/06/06 13:43:54 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>
#include <list>
#include <utility>
#include <iomanip>
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
void sortVector(char **argv, int ac);
void sortList(char **argv, int ac);
std::vector<int> mergeInsertionSort(std::vector<int> &vec);
std::list<int> mergeInsertionSort(std::list<int> &lst);
void print(std::vector<int> vec);
void print(std::list<int> vec);

#endif