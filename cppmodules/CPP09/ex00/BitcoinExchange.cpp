/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:11:26 by abashir           #+#    #+#             */
/*   Updated: 2024/05/08 12:36:27 by abashir          ###   ########.fr       */
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

void trim(std::string& str) 
{
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
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
        trim(key);
        std::string value = line.substr(pos + 1);
        trim(value);
        std::string date = key.substr(0, 4) + key.substr(5, 2) + key.substr(8, 2);
        _database.insert(std::make_pair(date, std::atof(value.c_str())));
    }
    if (_database.empty())
        throw checkFile();
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
    std::ifstream input(_file.c_str());
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

double BitcoinExchange::interpolate(std::string& date_key)
{
    std::multimap<std::string, double>::iterator lower = _database.lower_bound(date_key);
    if (lower != _database.end())
    {
        if (lower->first == date_key)
            return lower->second;
        else
        {
            if (lower != _database.begin())
                --lower;
        }
    }
    else if (lower != _database.begin())
        lower--;
    return lower->second;
}
bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
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
        if (exit_error(it->first.size() != 10 || count != 2 || it->second == "", "Error: bad input => " + it->first))
            continue;
        std::string date[3] = {it->first.substr(0, 4), it->first.substr(5, 2), it->first.substr(8, 2)};
        if (exit_error(!checkInt(date[0]) || !checkInt(date[1]) || !checkInt(date[2]) || checkType(it->second), "Error: bad input => " + it->first))
            continue;
        if (exit_error(std::atof(date[0].c_str()) < 2009 || std::atof(date[0].c_str()) > 2022 || std::atof(date[1].c_str()) < 1 || std::atof(date[1].c_str()) > 12 || std::atof(date[2].c_str()) < 1 || std::atof(date[2].c_str()) > 31, "Error: bad input => " + it->first))
            continue;
        if (exit_error((std::atof(date[1].c_str()) == 4 || std::atof(date[1].c_str()) == 6 || std::atof(date[1].c_str()) == 9 || std::atof(date[1].c_str()) == 11) && std::atof(date[2].c_str()) > 30, "Error: bad input => " + it->first))
            continue;
        if (exit_error(std::atof(date[1].c_str()) == 2 && isLeapYear(std::atof(date[0].c_str())) && std::atof(date[2].c_str()) > 29, "Error: bad input => " + it->first))
            continue;
        if (exit_error(std::atof(date[1].c_str()) == 2 && !isLeapYear(std::atof(date[0].c_str())) && std::atof(date[2].c_str()) > 28, "Error: bad input => " + it->first))
            continue;        
        if (exit_error(std::atof(it->second.c_str()) < 0, "Error: not a positive number."))
            continue;
        if (exit_error(std::atof(it->second.c_str()) > 1000, "Error: too large a number."))
            continue;
        std::cout << it->first << " => " << it->second;
        std::string date_key = date[0] + date[1] + date[2];
        std::cout << " = " << interpolate(date_key) * std::atof(it->second.c_str()) << std::endl;
        
    }
}