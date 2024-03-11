/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:34:47 by abashir           #+#    #+#             */
/*   Updated: 2024/02/13 16:06:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filename, std::string s1, std::string s2)
{
    this->_filename = filename;
    this->_s1 = s1;
    this->_s2 = s2;
}
File::~File()
{
    
}
std::string File::_getFilename()
{
  return (_filename);
}
std::string File::_getFind()
{
  return (_s1);
}
std::string File::_getReplace()
{
  return (_s2);
}
