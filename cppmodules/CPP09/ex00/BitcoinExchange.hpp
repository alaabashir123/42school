/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:35:13 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 15:14:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <array>
#include <iterator>
#include <exception>

class BitcoinExchange
{
    private:
        std::multimap<std::array<int, 3>, double> _database;
        std::multimap<std::string, std::string> _data;
        std::string _file;
        BitcoinExchange();
    public:
        BitcoinExchange(std::string file_name);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        void getDatabase();
        void getUserData();
        void createPair(std::string line);
        void createResult();
        double interpolate(std::array<int, 3> date_key);
};
#endif