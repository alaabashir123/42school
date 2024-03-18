/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:33:47 by abashir           #+#    #+#             */
/*   Updated: 2024/03/18 14:29:18 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
    // std::cout << "AMateria Default Constructor is called" << std::endl;
}
AMateria::AMateria(std::string const &type) : _type(type)
{
    // std::cout << "AMateria Type Constructor is called" << std::endl;
}
AMateria::~AMateria()
{
    // std::cout << "AMateria Destructor is called" << std::endl;
}
AMateria::AMateria(const AMateria &copy)
{
    // std::cout << "AMateria Copy Constructor is called" << std::endl;
    *this = copy;
}
AMateria & AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    return (*this);
}
std::string const & AMateria::getType() const
{
    return (this->_type);
}
void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria is used on " << target.getName() << std::endl;
}