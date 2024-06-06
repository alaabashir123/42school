/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:35:13 by abashir           #+#    #+#             */
/*   Updated: 2024/06/06 11:34:36 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <exception>

class BitcoinExchange
{
    private:
        std::multimap<std::string, double> _database;
        std::multimap<std::string, std::string> _data;
        std::string _file;
        BitcoinExchange();
        void getDatabase();
        void getUserData();
        void createPair(std::string line);
        void createResult();
        double interpolate(std::string &date_key);
        bool isLeapYear(int year);
    public:
        BitcoinExchange(std::string file_name);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
};
#endif