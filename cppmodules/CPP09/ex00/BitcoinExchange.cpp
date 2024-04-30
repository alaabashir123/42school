/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:11:26 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 14:44:20 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file_name) : _file(file_name)
{
    this->getDatabase();
    this->getUserData();
}
BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::~BitcoinExchange()
{
    
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        _database = rhs._database;
    }
    return (*this);
}

class checkFile : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Problem with the file";
    }
};
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