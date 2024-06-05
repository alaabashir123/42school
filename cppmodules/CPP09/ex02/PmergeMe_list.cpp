/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_list.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/06/05 17:43:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
    bool isOdd = false;
    if (lst.size() % 2 != 0) 
    {
        straggler = lst.back();
        lst.pop_back();
        return (true);
    }
    return (false);
}

template<typename T1, typename T2>
void print_pair(const std::pair<T1, T2>& pair) {
    std::cout << "(" << pair.first << ", " << pair.second << ")";
}

template<typename T1, typename T2>
void print_pair_list(const std::list<std::pair<T1, T2> >& pairs) {
    typename std::list<std::pair<T1, T2> >::const_iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it) {
        print_pair(*it);
        std::cout << " ";
    }
    std::cout << std::endl;
}
std::list<std::pair<int, int> > makePairs(std::list<int>& lst)
{
    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        std::list<int>::iterator itNext = it;
        itNext++;
        if (*it < *itNext)
            pairs.push_back(std::make_pair(*it, *itNext));
        else
            pairs.push_back(std::make_pair(*itNext, *it));
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

    if (size == 0) return indexes; // Handle empty input

    std::list<int> j;
    j.push_back(0);
    j.push_back(1);
    indexes.push_back(1);

    int lastJacobsthalNumber = 2;
    std::list<int>::iterator it = ++j.begin();  // Points to j[1]
    std::list<int>::iterator it2 = j.begin();   // Points to j[0]
    
    for (size_t i = 2; indexes.size() < size; ++i) {
        int nextJacobsthal = *it + 2 * (*it2);
        j.push_back(nextJacobsthal);

        if (i != 2) {
            if (nextJacobsthal <= size)
                indexes.push_back(nextJacobsthal);
        }
        for (int k = nextJacobsthal - 1; k > lastJacobsthalNumber && indexes.size() < size; --k) {
            if (k <= size) {
                indexes.push_back(k);
            }
        }
        lastJacobsthalNumber = nextJacobsthal;

        ++it;
        if (std::distance(j.begin(), it2) + 1 < j.size()) {
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
