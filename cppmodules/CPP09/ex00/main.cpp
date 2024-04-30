/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:33:45 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 14:46:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
    if (checkInt(input) || checkDouble(input) || checkFloat(input))
        return (0);
    else
    {
        std::cout << "Invalid input" << std::endl;
        return (1);
    }
}

int exit_error(int condition, std::string message)
{
    if (condition)
    {
        std::cout << message << std::endl;
        return (1);
    }
    return (0);
}

void trim(std::string& str) 
{
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
}

int check_file(std::string file_name, BitcoinExchange exchange)
{
    std::string line;
    std::multimap<std::string, std::string> data;
    std::ifstream input(file_name);
    if (exit_error(!input.is_open(), "Can't open the file"))
        return (1);
    if (std::getline(input, line)) 
    {
        trim(line);
        if (line != "date | value")
        {
            size_t pos = line.find("|");
            if (pos != std::string::npos) 
            {
                std::string key = line.substr(0, pos);
                trim(key);
                std::string value = line.substr(pos + 1);
                trim(value);
                data.insert(std::make_pair(key, value));
            } 
            else 
            {
                trim(line);
                data.insert(std::make_pair(line, ""));
            }
    }
    }
    while (std::getline(input, line))
    {
        size_t pos = line.find("|");
        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            trim(key);
            std::string value = line.substr(pos + 1);
            trim(value);
            data.insert(std::make_pair(key, value));
        }
        else
            data.insert(std::make_pair(line, ""));
    }
    if (exit_error(data.empty(), "Empty File"))
        return (1);
    std::map<std::string, std::string>::iterator it;
    int count;
    for (it = data.begin(); it != data.end(); ++it) 
    {
        count = 0;
        for (size_t i = 0; i < it->first.size(); i++)
        {
            if (it->first[i] == '-')
                count++;
        }
        // std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        if (it->first.size() != 10 || count != 2)
        {
            std::cout << "error" << std::endl;
            continue;
        }
        std::array<std::string, 3> date = {it->first.substr(0, 4), it->first.substr(5, 2), it->first.substr(8, 2)};
        // std::cout << count << std::endl;
        if (checkType(date[0]) || checkType(date[1]) || checkType(date[2]) || checkType(it->second))
            continue;
        if (std::atof(date[1].c_str()) < 1 || std::atof(date[1].c_str()) > 12 || std::atof(date[2].c_str()) < 1 || std::atof(date[2].c_str()) > 31)
        {
            std::cout << "invalid date " << it->first << std::endl;
            continue;
        }
        if (std::atof(it->second.c_str()) < 0 || std::atof(it->second.c_str()) > 1000)
        {
            std::cout << "Invalid value" << it->second << std::endl;
            continue;
        }
        for (int i = 0; i < 3; i++)
            std::cout << std::atof(date[i].c_str()) << "-";
        // std::cout << std::atof(it->second.c_str()) << std::endl;
        std::array<int, 3> date_key = {std::atoi(date[0].c_str()), std::atoi(date[1].c_str()), std::atoi(date[2].c_str())};
        std::multimap<std::array<int, 3>, double>::iterator lower = database.lower_bound(date_key);

    if (lower != database.end())
    {
        if (lower->first[0] == date_key[0] && lower->first[1] == date_key[1] && lower->first[2] == date_key[2])
            std::cout << "Exact" << std::endl;
        else
        {
            if (lower != database.begin())
                lower--;
            std::cout << "Not Exact" << std::endl;
        }
        // std::cout << "Key: {" << lower->first[0] << ", " << lower->first[1] << ", " << lower->first[2] << "}";
        // std::cout << ", Value: " << lower->second << std::endl;
        
    }
    else
        lower--;
    std::cout << "Key: {" << lower->first[0] << ", " << lower->first[1] << ", " << lower->first[2] << "}";
    std::cout << ", Value: " << lower->second * std::atof(it->second.c_str())  << std::endl;
    }

    return (0);
}


std::multimap<std::array<int, 3>, double> read_database()
{
    std::string line;
    std::multimap<std::array<int, 3>, double> data;
    std::ifstream input("data.csv");
    if (exit_error(!input.is_open(), "Can't open the file"))
        return (data);
    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t pos = line.find(",");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        std::array<int, 3> date = {std::atoi(key.substr(0, 4).c_str()), std::atoi(key.substr(5, 2).c_str()), std::atoi(key.substr(8, 2).c_str())};
        data.insert(std::make_pair(date, std::atof(value.c_str())));
    }
    if (exit_error(data.empty(), "Empty File"))
        return (data);
    return (data);
}

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (0);
    }
    try
    {
        BitcoinExchange exchange(argv[1]);
        // if (check_file(argv[1], exchange))
        //     return (0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    (void)argv;
}