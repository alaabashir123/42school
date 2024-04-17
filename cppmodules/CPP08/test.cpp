/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:42:22 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 14:50:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

void print(int i)
{
    std::cout << i << std::endl;
}
int main()
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);

    std::list<int>::const_iterator it;
    std::list<int>::const_iterator ite;

    ite = lst.end();

    for (it = lst.begin(); it != ite; ++it)
        std::cout << *it << std::endl;

    std::map<std::string, std::string> map;

    for_each(lst.begin(), lst.end(), print);
    map["key1"] = "Alaa";
    map["key2"] = "Bashir";
    std::cout << map["key1"];

    std::vector<int> v1;
        
}
