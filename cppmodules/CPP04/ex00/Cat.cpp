/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:28 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 15:17:21 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Default Cat constructor is called" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}
Cat::Cat(Cat const &copy) : Animal(copy)
{
	*this = copy;
}
Cat &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
    Animal::operator=(rhs);
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}