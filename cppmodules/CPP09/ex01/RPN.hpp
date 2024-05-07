/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:55:17 by abashir           #+#    #+#             */
/*   Updated: 2024/05/07 11:23:21 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <exception>

class invalidInput : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Error: Invalid input";
    }   
};

class invalidCal : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Error: Calculation error";
    }   
};
void checkInput(std::string argv);
int checkType(std::string input);
void calculateRPN(std::string argv);
#endif