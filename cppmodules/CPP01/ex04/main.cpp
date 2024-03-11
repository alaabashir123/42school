/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:30:49 by abashir           #+#    #+#             */
/*   Updated: 2024/02/15 13:13:12 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int exit_error(int condition, std::string message)
{
    if (condition)
    {
        std::cout << message << std::endl;
        return (1);
    }
    return (0);
}

std::string get_input(File& file_ob)
{
    std::string input_string;
    
    std::ifstream input(file_ob._getFilename().c_str());
    if (exit_error(!input.is_open(), "Can't open the file"))
        return ("");
    std::getline(input, input_string, '\0');
    exit_error(input_string.empty(), "Empty File");
    return (input_string);
}

int    create_output(File file_ob, std::string input_string)
{
    size_t i = 0;
    size_t pos = 0;
    
    std::string outputFile = file_ob._getFilename() + ".replace";
    std::ofstream output(outputFile.c_str());
    if (exit_error(!output.is_open(), "Can't create output file"))
        return (1);
    if (file_ob._getFind().empty())
        return (output << input_string, 0);
    while (input_string[i])
    {
        pos = input_string.find(file_ob._getFind(), i);
        if (i == pos)
        {
            output << file_ob._getReplace();
            i += file_ob._getFind().length();
        }
        else
        {
            output << input_string.substr(i, pos - i);
            i += (input_string.substr(i, pos - i)).length();
        }
    }
    return (0);
}

int main(int ac, char **argv)
{
    if (exit_error(ac != 4, "Invalid number of arguments"))
        return (1);
    File file_ob(argv[1], argv[2], argv[3]);
    std::string input_string = get_input(file_ob);
    if (input_string.empty())
        return (1);
    if (create_output(file_ob, input_string))
        return (1);
    return (0);
}