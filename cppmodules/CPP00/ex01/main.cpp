/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:12:47 by abashir           #+#    #+#             */
/*   Updated: 2024/02/07 17:24:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb;
    std::string input;
    while (1)
    {
        input = checkInput("Please Select ADD | SEARCH | EXIT");
        if (!input.compare("ADD"))
            pb.add();
        else if (!input.compare("SEARCH"))
            pb.search();
        else if (!input.compare("EXIT"))
            break ;
        else
            std::cout << "Invalid choice" << std::endl;
    }
}
