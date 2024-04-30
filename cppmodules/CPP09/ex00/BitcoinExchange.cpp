/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:11:26 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 15:27:19 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class checkFile : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Error: could not open file.";
    }
};

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {*this = copy;}
BitcoinExchange::BitcoinExchange(std::string file_name) : _file(file_name)
{
    this->getDatabase();
    this->getUserData();
    this->createResult();
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        _database = rhs._database;
        _data = rhs._data;
        _file = rhs._file;
    }
    return (*this);
}

void BitcoinExchange::getDatabase()
{
    std::string line;
    std::ifstream input("data.csv");
    if (!input.is_open())
        throw checkFile();
    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t pos = line.find(",");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        std::array<int, 3> date = {std::atoi(key.substr(0, 4).c_str()), std::atoi(key.substr(5, 2).c_str()), std::atoi(key.substr(8, 2).c_str())};
        _database.insert(std::make_pair(date, std::atof(value.c_str())));
    }
    if (_database.empty())
        throw checkFile();
}

void trim(std::string& str) 
{
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
}

void BitcoinExchange::createPair(std::string line)
{
    size_t pos = line.find("|");
    if (pos != std::string::npos) 
    {
        std::string key = line.substr(0, pos);
        trim(key);
        std::string value = line.substr(pos + 1);
        trim(value);
        _data.insert(std::make_pair(key, value));
    } 
    else 
    {
        trim(line);
        _data.insert(std::make_pair(line, ""));
    }
}
void BitcoinExchange::getUserData()
{
    std::string line;
    std::ifstream input(_file);
    if (!input.is_open())
        throw checkFile();
    if (std::getline(input, line)) 
    {
        trim(line);
        if (line != "date | value")
            createPair(line);
    }
    while (std::getline(input, line))
    {
        createPair(line);
    }
    if (_data.empty())
        throw checkFile();
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
    if (checkInt(input) || checkDouble(input) || checkFloat(input))
        return (0);
    else
        return (1);
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

double BitcoinExchange::interpolate(std::array<int, 3> date_key)
{
    std::multimap<std::array<int, 3>, double>::iterator lower = _database.lower_bound(date_key);
    if (lower != _database.end())
    {
        if (lower->first[0] == date_key[0] && lower->first[1] == date_key[1] && lower->first[2] == date_key[2]);
        else
        {
            if (lower != _database.begin())
                lower--;
        }
    }
    else
        lower--;
    return lower->second;
}
void BitcoinExchange::createResult()
{
    std::map<std::string, std::string>::iterator it;
    int count;
    for (it = _data.begin(); it != _data.end(); it++) 
    {
        count = 0;
        for (size_t i = 0; i < it->first.size(); i++)
        {
            if (it->first[i] == '-')
                count++;
        }
        if (exit_error(it->first.size() != 10 || count != 2, "Error: bad input => " + it->first))
            continue;
        std::array<std::string, 3> date = {it->first.substr(0, 4), it->first.substr(5, 2), it->first.substr(8, 2)};
        if (exit_error(checkType(date[0]) || checkType(date[1]) || checkType(date[2]) || checkType(it->second), "Error: bad input => " + it->first))
            continue;
        if (exit_error(std::atof(date[1].c_str()) < 1 || std::atof(date[1].c_str()) > 12 || std::atof(date[2].c_str()) < 1 || std::atof(date[2].c_str()) > 31, "Error: bad input => " + it->first))
            continue;
        if (exit_error(std::atof(it->second.c_str()) < 0, "Error: not a positive number."))
            continue;
        if (exit_error(std::atof(it->second.c_str()) > 1000, "Error: too large a number."))
            continue;
        std::cout << it->first << " => " << it->second;
        std::array<int, 3> date_key = {std::atoi(date[0].c_str()), std::atoi(date[1].c_str()), std::atoi(date[2].c_str())};
        std::cout << " = " << interpolate(date_key) * std::atof(it->second.c_str()) << std::endl;
        
    }
}