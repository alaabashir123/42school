/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/06/04 13:08:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkInt(std::string input)
{
    size_t i = 0;
    if (input[i] == '+')
        i++;
    if (input[i] == '-')
        return (false);
    for (; i < input.length(); i++)
    {
        if ((!isdigit(input[i])))
            return (false);
    }
    if (std::atof(input.c_str()) > INT_MAX)
        return (false);
    return (true);
}

void checkInput(char **argv, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        if (strcmp(argv[i], "") == 0 || strcmp(argv[i], " ") == 0)
            throw invalidInput();
        if (argv[i][0] == ' ')
        {
            int j = 0;
            while (argv[i][j] == ' ')
                j++;
            if (argv[i][j] == '\0')
                throw invalidInput();
        }
        std::istringstream input(argv[i]);
        std::string x;
        while (getline(input, x, ' '))
        {
            if (x.empty())
                continue;
            if (!checkInt(x))
                throw invalidInput();
        }
    }
}

void readInput(char **argv, int ac, std::vector<int> &vec)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream input(argv[i]);
        std::string x;
        while (getline(input, x, ' '))
        {
            if (x.empty())
                continue;
            vec.push_back(std::atoi(x.c_str()));
        }
    }
}

void readInput(char **argv, int ac, std::list<int> &lst)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream input(argv[i]);
        std::string x;
        while (getline(input, x, ' '))
        {
            if (x.empty())
                continue;
            lst.push_back(std::atoi(x.c_str()));
        }
    }
}

void insertion_sort_pairs(std::vector<std::pair<int, int> >& pairs, size_t n) {
    if (n <= 1)
        return;
    insertion_sort_pairs(pairs, n - 1);
    const std::pair<int, int> newPair = pairs[n - 1];
    size_t i = n - 1;
    while (i > 0 && pairs[i - 1].second > newPair.second) {
        pairs[i] = pairs[i - 1];
        i--;
    }
    pairs[i] = newPair;
}

void print(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout <<std::endl;
}
std::vector<int>::iterator bisearch(std::vector<int>& S, int item)
{
    return std::upper_bound(S.begin(), S.end(), item);
}
std::vector<int> mergeInsertionSort(std::vector<int>& vec) 
{
    bool isOdd = false;
    int straggler;
    if (vec.size() % 2 != 0) 
    {
        straggler = vec.back();
        isOdd = true;
        vec.pop_back();
    }
    if (vec.size() <= 1)
        return (vec);

    std::vector<std::pair<int, int> > pairs(vec.size() / 2);
    for (size_t i = 0; i < vec.size(); i += 2)
        pairs[i / 2] = std::make_pair(vec[i], vec[i + 1]);
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    
    insertion_sort_pairs(pairs, pairs.size());

    std::vector<int> S;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    if (isOdd)
        pend.push_back(straggler);
    std::cout << "S: ";
    print(S);
    std::cout << "pend: ";
    print(pend);
    std::cout << "---------------\n";
    size_t size = pend.size();
    std::vector<int> j(size + 1);
    std::vector<int> indexes;
    j[0] = 0;
    j[1] = 1;
    int lastJacobsthalNumber = 2;
    indexes.push_back(j[1]);
    // std::cout << "S: ";
    // print(S);
    int count = 1;
    for (size_t i = 2; indexes.size() < size; i++) 
    {
        j[i] = j[i - 1] + 2 * j[i - 2];
        if (i != 2)
        {
            std::cout << "hi " << j[i] << " i[i]: " << i << std::endl;
            if (j[i] <= size)
                indexes.push_back(j[i]);
        }

        for (int k = j[i] - 1; k > lastJacobsthalNumber; k--)
        {
            std::cout << "hi2 " << j[i] << " i[i]: " << i << std::endl;
            if (k <= size)
                indexes.push_back(k);
        }
        std::cout << "S: ";
        print(S);
        lastJacobsthalNumber = j[i];
        count++;
    }
    std::cout << "count: " << count << std::endl;
    // std::cout << "S: ";
    // print(S);
    std::cout << "indexes: ";
    print(indexes);
    // std::cout << "pend: ";
    // print(pend);
    for (size_t i = 0; i < pend.size(); i++) 
    {
        
        int item = pend[indexes[i] - 1];
        std::cout << "item: " << item << std::endl;
        std::vector<int>::iterator it =  bisearch(S, item);
        std::cout << "bisearch : "<< *it << std::endl;
        S.insert(it, item);
        print(S);
    }
    // S.insert(it, item);
    return (S);
    // print(S);
}


