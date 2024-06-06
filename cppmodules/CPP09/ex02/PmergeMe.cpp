/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/06/06 13:53:06 by abashir          ###   ########.fr       */
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
        if (std::string(argv[i]) == "" || std::string(argv[i]). == " ")
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

std::vector<int> getIndexes(std::vector<int> pend)
{
    std::vector<int> indexes;
    int size = pend.size();
    std::vector<int> j(size + 2);
    j[0] = 0;
    j[1] = 1;
    int lastJacobsthalNumber = 2;
    indexes.push_back(j[1]);
    for (int i = 2; static_cast<int>(indexes.size()) < size; i++) 
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
    
    std::vector<int> indexes = getIndexes(pend);
    insertPend(pend, S, indexes);
    return (S);
}

void sortVector(char **argv, int ac)
{
    clock_t start_vec = clock();
    std::vector<int> vec;
    readInput(argv, ac, vec);
    std::vector<int> copy(vec);
    if (vec.empty() || vec.size() == 1)
        throw std::runtime_error("Error");
    std::vector<int> S = mergeInsertionSort(vec);
    clock_t end_vec = clock();
    std::cout << "Before : ";            
    print(copy);
    std::cout << "After :  ";
    print(S);
    double elapsedTime_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(7) << elapsedTime_vec << std::endl;
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

void sortPairs(std::list<std::pair<int, int> >& pairs, size_t n) 
{
    if (n <= 1)
        return;
    sortPairs(pairs, n - 1);
    
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    std::advance(it, n - 1);
    const std::pair<int, int> newPair = *it;
        
    std::list<std::pair<int, int> >::iterator itbef = it;
    itbef--;
    
    size_t i = n - 1;
    while (i > 0 && (*itbef).second > newPair.second) 
    {
        *it = *itbef;
        it--;
        itbef--;
        i--;
    }
    *it = newPair;
}

void print(std::list<int> lst)
{
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout <<std::endl;
}
std::list<int>::iterator bisearch(std::list<int>& S, int item)
{
    return std::upper_bound(S.begin(), S.end(), item);
}

bool getStaggler(std::list<int>& lst, int &straggler)
{
    if (lst.size() % 2 != 0) 
    {
        straggler = lst.back();
        lst.pop_back();
        return (true);
    }
    return (false);
}

std::list<std::pair<int, int> > makePairs(std::list<int>& lst)
{
    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end();)
    {
        std::list<int>::iterator itNext = it;
        itNext++;
        if (*it < *itNext)
            pairs.push_back(std::make_pair(*it, *itNext));
        else
            pairs.push_back(std::make_pair(*itNext, *it));
        it++;
        it++;
    }
    return (pairs);
}

void createChains(std::list<int> &S, std::list<int> &pend, std::list<std::pair<int, int> > pairs)
{
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) 
    {
        S.push_back((*it).second);
        pend.push_back((*it).first);
    }
}

std::list<int> getIndexes(const std::list<int>& pend) {
    std::list<int> indexes;
    size_t size = pend.size();

    if (size == 0) 
        return indexes;

    std::list<int> j;
    j.push_back(0);
    j.push_back(1);
    indexes.push_back(1);

    size_t lastJacobsthalNumber = 2;
    std::list<int>::iterator it = ++j.begin();
    std::list<int>::iterator it2 = j.begin();
    
    for (size_t i = 2; indexes.size() < size; ++i) {
        size_t nextJacobsthal = *it + 2 * (*it2);
        j.push_back(nextJacobsthal);

        if (i != 2) {
            if (nextJacobsthal <= size)
                indexes.push_back(nextJacobsthal);
        }
        for (size_t k = nextJacobsthal - 1; k > lastJacobsthalNumber && indexes.size() < size; --k) {
            if (k <= size) {
                indexes.push_back(k);
            }
        }
        lastJacobsthalNumber = nextJacobsthal;

        ++it;
        if (std::distance(j.begin(), it2) + 1 < static_cast<long>(j.size())) {
            ++it2;
        }
    }
    return indexes;
}

void insertPend(std::list<int> pend, std::list<int> &S, std::list<int> indexes)
{
    std::list<int>::iterator it = indexes.begin();
    for (size_t i = 0; i < pend.size(); i++) 
    {
        std::list<int>::iterator itpend = pend.begin();
        std::advance(itpend, *it - 1);
        int item = *itpend;
        std::list<int>::iterator itBi =  bisearch(S, item);
        S.insert(itBi, item);
        it++;
    }
}

std::list<int> mergeInsertionSort(std::list<int>& lst) 
{
    int straggler;
    bool isOdd = getStaggler(lst, straggler);
    if (lst.size() <= 1)
        return (lst);

    std::list<std::pair<int, int> > pairs = makePairs(lst);
    sortPairs(pairs, pairs.size());
    std::list<int> S;
    std::list<int> pend ;
    createChains(S, pend, pairs);
    if (isOdd)
        pend.push_back(straggler);
    
    std::list<int> indexes = getIndexes(pend);
    insertPend(pend, S, indexes);
    return (S);
}

void sortList(char **argv, int ac)
{
    clock_t start_lst = clock();
    std::list<int> lst;
    std::list<int> copy_list(lst);
    readInput(argv, ac, lst);
    if (lst.empty() || lst.size() == 1)
        throw std::runtime_error("Error");
    std::list<int> S_list = mergeInsertionSort(lst);
    clock_t end_lst = clock();
    double elapsedTime_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list   : " << std::fixed << std::setprecision(7) << elapsedTime_lst << std::endl;
    
}