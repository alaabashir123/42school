/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:37:57 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:39:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponA) : _name(name), _weaponA(weaponA)
{

}
HumanA::~HumanA()
{
    
}
void HumanA::attack()
{
    std::cout << this->_name << " attacks with their ";
    std::cout << this->_weaponA.getType() << std::endl;
}