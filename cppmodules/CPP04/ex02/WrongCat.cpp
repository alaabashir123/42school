/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:34:12 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 15:35:06 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor is called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	*this = copy;
}
WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
    WrongAnimal::operator=(rhs);
	return (*this);
}
void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}