/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:42:05 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:30:18 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure Default Constructor is called" << std::endl;
}
Cure::~Cure()
{
    // std::cout << "Cure Destructor is called" << std::endl;
}
Cure::Cure(const Cure &copy) : AMateria(copy)
{
    // std::cout << "Cure Copy Constructor is called" << std::endl;
    *this = copy;
}

Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);

}
AMateria* Cure::clone() const
{
    return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}