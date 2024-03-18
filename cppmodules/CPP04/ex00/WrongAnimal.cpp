/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:09 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 15:33:11 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor is called" << std::endl;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor is called" << std::endl;  
}
WrongAnimal::WrongAnimal(const std::string &type): _type(type)
{
    std::cout << "WrongAnimal Type constructor is called" << std::endl;
    
}
WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
    std::cout << "WrongAnimal copy constructor is called" << std::endl;
    *this = copy;
}
WrongAnimal & WrongAnimal::operator=(WrongAnimal const &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;    
}

std::string WrongAnimal::getType() const
{
    return(this->_type);
}
