/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:39 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 13:38:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Dog constructor is called" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}
Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	*this = copy;
}
Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}