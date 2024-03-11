/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:02:34 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 15:58:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_weaponB;
    
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon& weapon);
};