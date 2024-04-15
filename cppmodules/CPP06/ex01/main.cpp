/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:23:07 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 16:33:41 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data d;
    d.num = 10;
    std::cout << "data before: " << d.num << std::endl;
    uintptr_t p = Serializer::serialize(&d);
    Data *d_c = Serializer::deserialize(p);
    std::cout << "data after: " << d_c->num << std::endl;
    
}