/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:10:23 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 17:38:50 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void (Harl::*functionArray[4])();
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
    
};