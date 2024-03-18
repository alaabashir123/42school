/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:28 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 13:27:30 by abashir          ###   ########.fr       */
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
	std::cout << "Cat copy constructor is called" << std::endl;
	*this = copy;
}
Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}