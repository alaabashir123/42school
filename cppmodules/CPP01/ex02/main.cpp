/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:39:47 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:28:22 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string& stringREF = string; 

    std::cout << "Address of string:         " << &string << std::endl;
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string:         " << string << std::endl;
    std::cout << "Value held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value held by stringREF: " << stringREF << std::endl;    
    
}