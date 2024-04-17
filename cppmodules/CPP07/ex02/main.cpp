/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:12:14 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 13:47:13 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> arrayInt(5);
	for (unsigned int i = 0; i < arrayInt.size(); i++)
		arrayInt[i] = i;

    Array<int> arrayInt2(5);
	for (unsigned int i = 0; i < arrayInt2.size(); i++)
		arrayInt2[i] = i + 2;
        
    std::cout << "Array of int :        ";
	for (unsigned int i = 0; i < arrayInt.size(); i++)
		std::cout << arrayInt[i] << " ";
	std::cout << std::endl;

    std::cout << "Array2 of int :       ";
	for (unsigned int i = 0; i < arrayInt2.size(); i++)
		std::cout << arrayInt2[i] << " ";
	std::cout << std::endl;
    
    std::cout << "Copy Array of int :   ";
    Array<int> arrayCopy(arrayInt);
	for (unsigned int i = 0; i < arrayCopy.size(); i++)
		std::cout << arrayCopy[i] << " ";
	std::cout << std::endl;

    std::cout << "Assign Array2 of int: ";
    arrayCopy = arrayInt2;
	for (unsigned int i = 0; i < arrayCopy.size(); i++)
		std::cout << arrayCopy[i] << " ";
	std::cout << std::endl;
        
	Array<std::string> arrayString(5);
    
    std::cout << "Array of string:      ";
	for (unsigned int i = 0; i < arrayString.size(); i++)
		arrayString[i] = 'a' + i;

	for (unsigned int i = 0; i < arrayString.size(); i++)
		std::cout << arrayString[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << arrayInt[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}