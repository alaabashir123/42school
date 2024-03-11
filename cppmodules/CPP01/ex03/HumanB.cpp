/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:04:27 by abashir           #+#    #+#             */
/*   Updated: 2024/02/15 12:44:18 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weaponB = NULL;
}
HumanB::~HumanB()
{
}
void HumanB::attack()
{
    std::cout << this->_name << " attacks with their ";
    if (this->_weaponB != NULL)
        std::cout << this->_weaponB->getType() << std::endl;
    else
        std::cout << "unknown Weapon" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weaponB = &weapon;
}
