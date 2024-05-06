/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:20:45 by abashir           #+#    #+#             */
/*   Updated: 2024/05/06 15:27:01 by abashir          ###   ########.fr       */
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

class invalidInput : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Error: Invalid input";
    }   
};

bool checkInt(std::string input);
void checkInput(std::string argv);
void readInput(std::string argv, std::list<int> &lst, std::vector<int> &vec);
void mergeInsertionSort(std::vector<int> &vec, size_t left, size_t right, size_t k);
void mergeInsertionSort(std::list<int> &lst, size_t left, size_t right, size_t k);

#endif