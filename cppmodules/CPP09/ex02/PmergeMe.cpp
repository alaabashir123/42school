/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/05/09 14:48:28 by abashir          ###   ########.fr       */
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
    if (std::atoi(input.c_str()) < 0)
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

void mergeInsertionSort(std::vector<int>& vec) {
    bool isOdd = false;
    int straggler;
    if (vec.size() % 2 != 0) {
        straggler = vec.back();
        isOdd = true;
        vec.pop_back();
    }
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs(vec.size() / 2);
    for (size_t i = 0; i < vec.size(); i += 2) {
        pairs[i / 2] = std::make_pair(vec[i], vec[i + 1]);
    }
    for (size_t i = 0; i < pairs.size(); i++) {
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

    size_t size = S.size();
    std::vector<int> j(size + 1);
    std::vector<int> indexes;
    j[0] = 0;
    j[1] = 1;
    int lastJacobsthalNumber = 2;
    indexes.push_back(j[1]);
    for (size_t i = 2; indexes.size() < size + 1; i++) {
        j[i] = j[i - 1] + 2 * j[i - 2];
        if (i != 2)
            indexes.push_back(j[i]);

        for (int k = j[i] - 1; k > lastJacobsthalNumber; k--)
            indexes.push_back(k);

        lastJacobsthalNumber = j[i];
    }

    for (size_t i = 0; i < pend.size(); i++) {
        auto it = S.begin() + indexes[i];
        S.insert(it, pend[i]);
    }

    for (size_t i = 0; i < indexes.size(); i++)
        std::cout << " " << indexes[i] << std::endl;
    for (size_t i = 0; i < S.size(); i++)
        std::cout << S[i] << " ";
}


