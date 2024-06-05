/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/06/05 17:39:47 by abashir          ###   ########.fr       */
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


void sortPairs(std::vector<std::pair<int, int> >& pairs, size_t n) {
    if (n <= 1)
        return;
    sortPairs(pairs, n - 1);
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

bool getStaggler(std::vector<int>& vec, int &straggler)
{
    bool isOdd = false;
    if (vec.size() % 2 != 0) 
    {
        straggler = vec.back();
        vec.pop_back();
        return (true);
    }
    return (false);
}
std::vector<std::pair<int, int> > makePairs(std::vector<int>& vec)
{
    std::vector<std::pair<int, int> > pairs(vec.size() / 2);
    
    for (size_t i = 0; i < vec.size(); i += 2)
        pairs[i / 2] = std::make_pair(vec[i], vec[i + 1]);
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        if (pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    return (pairs);
}

void createChains(std::vector<int> &S, std::vector<int> &pend, std::vector<std::pair<int, int> > pairs)
{
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
}

std::vector<int> getIndexex(std::vector<int> pend)
{
    std::vector<int> indexes;
    size_t size = pend.size();
    std::vector<int> j(size + 1);
    j[0] = 0;
    j[1] = 1;
    int lastJacobsthalNumber = 2;
    indexes.push_back(j[1]);
    for (size_t i = 2; indexes.size() < size; i++) 
    {
        j[i] = j[i - 1] + 2 * j[i - 2];
        if (i != 2)
        {
            if (j[i] <= size)
                indexes.push_back(j[i]);
        }

        for (int k = j[i] - 1; k > lastJacobsthalNumber; k--)
        {
            if (k <= size)
                indexes.push_back(k);
        }
        lastJacobsthalNumber = j[i];
    }
    return (indexes);
}

void insertPend(std::vector<int> pend, std::vector<int> &S, std::vector<int> indexes)
{
    for (size_t i = 0; i < pend.size(); i++) 
    {
        
        int item = pend[indexes[i] - 1];
        std::vector<int>::iterator it =  bisearch(S, item);
        S.insert(it, item);
    }
}

std::vector<int> mergeInsertionSort(std::vector<int>& vec) 
{
    int straggler;
    bool isOdd = getStaggler(vec, straggler);
    if (vec.size() <= 1)
        return (vec);

    std::vector<std::pair<int, int> > pairs = makePairs(vec);
    sortPairs(pairs, pairs.size());

    std::vector<int> S;
    std::vector<int> pend;
    createChains(S, pend, pairs);
    if (isOdd)
        pend.push_back(straggler);
    
    std::vector<int> indexes = getIndexex(pend);
    insertPend(pend, S, indexes);
    return (S);
}


