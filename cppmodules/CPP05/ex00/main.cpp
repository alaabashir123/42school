/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:56 by abashir           #+#    #+#             */
/*   Updated: 2024/05/14 12:33:55 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat c("Alaa", 3);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        std::cout << c << std::endl;
        std::cout << "------------------------" << std::endl;
        Bureaucrat b("Bashir", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "------------------------" << std::endl;
        Bureaucrat b("Bashir", 0);
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (1);
}