/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:49:27 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:24:20 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default Animal constructor is called" << std::endl;
}
Animal::~Animal()
{
    std::cout << "Animal destructor is called" << std::endl;  
}
Animal::Animal(const std::string &type): _type(type)
{
    std::cout << "Animal constructor is called" << std::endl;
}
Animal::Animal(Animal const &copy)
{
    std::cout << "Animal copy constructor is called" << std::endl;
    *this = copy;
}
Animal & Animal::operator=(Animal const &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;    
}

std::string Animal::getType() const
{
    return(this->_type);
}
