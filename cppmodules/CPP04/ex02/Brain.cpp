/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:50:23 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 16:16:56 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor is called" << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor is called" << std::endl;    
}
Brain::Brain(Brain const &copy)
{
    *this = copy;
}
Brain &Brain::operator=(Brain const &rhs)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = rhs._ideas[i];
    return (*this);
}