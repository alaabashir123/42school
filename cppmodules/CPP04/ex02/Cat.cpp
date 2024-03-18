/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:28 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 15:20:55 by abashir          ###   ########.fr       */
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
	std::cout << "Cat copy constructor is called" << std::endl;
	_ideas = new Brain();
	*this = copy;
}
Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		if (_ideas)
		{
			delete _ideas;
			_ideas =NULL;
		}
		this->_type = rhs._type;
		this->_ideas = new Brain(*rhs._ideas);
	}
	return (*this);
}
void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}
