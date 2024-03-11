/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:58:23 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 15:27:47 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name);

};
