/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:16:28 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:42:54 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        DiamondTrap();
        std::string _name;
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap& operator=(const DiamondTrap &rhs);
        void whoAmI();
};

#endif