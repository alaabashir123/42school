/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:35:56 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 14:10:00 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("Alaa", 12);
        Bureaucrat bureaucrat2("Bashir", 11);
        Form form("Food From", 11, 0);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
        bureaucrat2.signForm(form);
        std::cout << form << std::endl;
                
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 1;
}