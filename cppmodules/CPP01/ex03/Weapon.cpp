/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:55:51 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:38:22 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    this->_type = name;
}
Weapon::~Weapon()
{
    
}
const std::string& Weapon::getType()
{
    return (this->_type);
}
void Weapon::setType(std::string type)
{
    this->_type = type;
}
