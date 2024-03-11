/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:56:05 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:38:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
  private:
    std::string _type;  
  public:
    Weapon(std::string name);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);
};