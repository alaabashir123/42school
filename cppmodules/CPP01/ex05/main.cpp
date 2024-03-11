/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:39:10 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 17:45:33 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl test;
    test.complain("DEBUG");
    test.complain("INFO");
    test.complain("WARNING");
    test.complain("ERROR");
    test.complain("");
}