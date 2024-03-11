/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:13:30 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 18:12:34 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    functionArray[0] = &Harl::debug;
    functionArray[1] = &Harl::info;
    functionArray[2] = &Harl::warning;
    functionArray[3] = &Harl::error;
}

Harl::~Harl()
{
}
void Harl::debug( void )
{
    std::cout << "[ DEBUG! ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO! ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;

}

void Harl::warning( void )
{
    std::cout << "[ WARNING! ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR! ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functionArray[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
