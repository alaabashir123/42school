/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:07:25 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:22:48 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAPTRAP_HPP
#define SCRAPTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap(ScavTrap const &copy);
        ScavTrap& operator=(ScavTrap const &rhs);
        void attack(const std::string& target);
        void guardGate(); 
};

#endif