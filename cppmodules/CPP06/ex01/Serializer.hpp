/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:19:28 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 16:58:55 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
typedef unsigned long uintptr_t;
struct Data
{
    int num;
};

class Serializer
{
    private:
        Serializer();
    public:
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &rhs);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif