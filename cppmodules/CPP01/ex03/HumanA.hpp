/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:34:49 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 15:58:06 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weaponA;
    
    public:
        HumanA(std::string name, Weapon& weaponA);
        ~HumanA();
        void attack();

    
};