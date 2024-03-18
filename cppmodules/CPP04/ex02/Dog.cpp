/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:19:39 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 15:21:12 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _ideas(new Brain())
{
	std::cout << "Default Dog constructor is called" << std::endl;
}
Dog::~Dog()
{
	delete _ideas;
	std::cout << "Dog destructor is called" << std::endl;
}
Dog::Dog(Dog const &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	_ideas = new Brain();
	*this = copy;
}
Dog &Dog::operator=(Dog const &rhs)
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
void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}