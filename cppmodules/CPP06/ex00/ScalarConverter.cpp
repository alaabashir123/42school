/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:32:08 by abashir           #+#    #+#             */
/*   Updated: 2024/04/15 16:13:27 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {*this = copy;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {(void)rhs; return (*this);}

bool checkChar(std::string input)
{
    if (input.length() == 1 && isalpha(input[0]) && std::isprint(input[0]))
        return (true);
    return (false);
}

bool checkInt(std::string input)
{
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.length(); i++)
    {
        if ((!isdigit(input[i])))
            return (false);
    }
    return (true);
}

bool checkDouble(std::string input)
{
    int found = 0;
    size_t i = 0;
    if (input.find('.') == 0 || input.find('.') == input.length() - 1 || input.find('.') == std::string::npos)
        return (false);
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.length(); i++)
    {
        if (input[i] == '.')
            found++;
        if ((!isdigit(input[i]) && input[i] != '.') || found > 1)
            return (false);
    }
    return (true);  
}

bool checkFloat(std::string input)
{
    int found = 0;
    size_t i = 0;
    if (input.find('.') == 0 || input.find('.') == input.length() - 2 || input.find('.') == std::string::npos || input[input.length() - 1] != 'f')
        return (false);
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (; i < input.length() - 1; i++)
    {
        if (input[i] == '.')
            found++;
        if ((!isdigit(input[i]) && input[i] != '.') || found > 1)
            return (false);
    }
    return (true);
}

int checkType(std::string input)
{
    if (checkChar(input))
        return (0);
    if (checkInt(input) || checkDouble(input) || checkFloat(input))
        return (1);
    else if (!input.compare("+inf") || !input.compare("-inf")  || !input.compare("inf") \
			|| 	!input.compare("nan")  || !input.compare("-nan")  || !input.compare("+nan") \
            || !input.compare("inff") || !input.compare("-inff") || !input.compare("+inff") \
			|| 	!input.compare("nanf") || !input.compare("-nanf") || !input.compare("+nanf"))
		return (1);
    else
    {
        std::cout << "Invalid input" << std::endl;
        return (2);
    }
}

void convertChar(std::string input)
{
    std::cout << "char:   " << "'" << input << "'" << std::endl;
    std::cout << "int:    " << static_cast<int>(input[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
    std::cout << "float:  " << static_cast<float>(input[0]) << ".0f" << std::endl;
}

void convertInt(std::string input)
{
    int num;
    try
    {
        num = std::stoi(input);
    }
    catch(const std::exception& e)
    {
        std::cout << "char:   " << "impossible" << std::endl;
        std::cout << "int:    " << "impossible" << std::endl;
        return;
    }
    if (std::isprint(num))
        std::cout << "char:   " << "'" << static_cast<char>(num) << "'" << std::endl;
    else
        std::cout << "char:   " << "Non displayable" << std::endl;
    std::cout << "int:    " << static_cast<int>(num) << std::endl;
}

void convertDouble(std::string input)
{
    double num;
    try
    {
        num = std::stod(input);
    }
    catch(const std::exception& e)
    {
        std::cout << "double:  " << "impossible" << std::endl;
        return ;
    }
    std::cout << "double: " << static_cast<double>(num);
    if (num == static_cast<int>(num))
        std::cout << ".0";
    std::cout << std::endl;
}

void convertFloat(std::string input)
{
    float num;
    try
    {
        num = std::stof(input);
    }
    catch(const std::exception& e)
    {
        std::cout << "float:  " << "impossible" << std::endl;
        return ;
    }
    std::cout << "float:  " << static_cast<double>(num);
    if (num == static_cast<int>(num))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::convert(std::string input)
{
    int type = checkType(input);
    if (type == 2)
        return;
    if (type == 0)
        return (convertChar(input));
    convertInt(input);
    convertFloat(input);
    convertDouble(input);
}