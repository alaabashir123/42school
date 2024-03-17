/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:16:36 by abashir           #+#    #+#             */
/*   Updated: 2024/03/17 12:37:15 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
        FragTrap();
    public:
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap(FragTrap const &copy);
        FragTrap& operator=(FragTrap const &copy);
        void highFiveGuys(void);
        
};

#endif