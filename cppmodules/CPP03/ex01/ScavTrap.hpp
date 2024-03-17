/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:00:30 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 11:46:35 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

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