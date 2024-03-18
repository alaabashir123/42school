/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:48:51 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:30:35 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice Default Constructor is called" << std::endl;
}
Ice::~Ice()
{
    // std::cout << "Ice Destructor is called" << std::endl;
}
Ice::Ice(const Ice &copy) : AMateria(copy)
{
    // std::cout << "Ice Copy Constructor is called" << std::endl;
    *this = copy;
}

Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);

}
AMateria* Ice::clone() const
{
    return (new Ice(*this));
}
void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}