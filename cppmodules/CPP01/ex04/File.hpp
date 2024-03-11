/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:31:22 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:07:05 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

class File
{
  private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
  public:
    File(std::string filename, std::string s1, std::string s2); 
    ~File();
    std::string _getFilename();
    std::string _getFind();
    std::string _getReplace();
};