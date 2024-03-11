/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:28 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 16:22:19 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _ideas(new Brain())
{
	std::cout << "Default Cat constructor is called" << std::endl;
}
Cat::~Cat()
{
	delete _ideas;
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
	this->_ideas = new Brain(*rhs._ideas);
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}