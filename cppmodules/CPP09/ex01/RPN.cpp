/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:20:43 by abashir           #+#    #+#             */
/*   Updated: 2024/04/30 17:37:52 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
    if (std::atoi(input.c_str()) > 9)
        return (false);
    return (true);
}

int checkType(std::string input)
{
    if ((input == "/" || input == "*" || input == "+" || input == "-") && input.length() == 1)
        return (1);
    else if (checkInt(input))
        return (0);
    else
        return (2);
}


void checkInput(std::string argv)
{
    std::istringstream input(argv);
    std::string x;
    int nums = 0;
    int ops = 0;
    int res;
    while (getline(input, x, ' '))
    {
        if (x.empty())
            continue;
        res = checkType(x);
        if (res == 2)
            throw invalidInput();
        else if (res == 1)
            ops++;
        else if (res == 0)
            nums++;
    }
    if (nums - ops != 1)
        throw invalidInput();
}

void calculateRPN(std::string argv)
{
    std::stack<int> st;
    std::istringstream input(argv);
    std::string x;
    int a;
    int b;
    while (getline(input, x, ' '))
    {
        
        if (x.empty())
            continue;
        if (checkType(x) == 0)
            st.push(std::atoi(x.c_str()));
        else if (checkType(x) == 1)
        {
            if (st.size() < 2)
                throw invalidCal();
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (x == "+")
                st.push(a + b);
            if (x == "-")
                st.push(a - b);
            if (x == "*")
                st.push(a * b);
            if (x == "/")
            {
                if (b == 0) 
                    throw invalidCal();
                st.push(a / b);
            }
        }
    }
    if (st.size() != 1)
        throw invalidCal();
    std::cout << st.top() << std::endl;
}