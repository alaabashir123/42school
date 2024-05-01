/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:25:28 by abashir           #+#    #+#             */
/*   Updated: 2024/05/01 15:06:06 by abashir          ###   ########.fr       */
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

void checkInput(std::string argv)
{
    std::istringstream input(argv);
    std::string x;
    while (getline(input, x, ' '))
    {
        if (x.empty())
            continue;
        if (!checkInt(x))
            throw invalidInput();
    }
}

void readInput(std::string argv, std::list<int> &lst, std::vector<int> &vec)
{
    std::istringstream input(argv);
    std::string x;
    while (getline(input, x, ' '))
    {
        if (x.empty())
            continue;
        lst.push_back(std::atoi(x.c_str()));
        vec.push_back(std::atoi(x.c_str()));
    }
}

void insertionSort(std::vector<int> &vec, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; i++)
    {
        int key = vec[i];
        size_t j = i - 1;
        while (j >= left && key < vec[j])
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }    
}

void merge(std::vector<int> &vec, size_t left, size_t mid, size_t right)
{
    size_t sub1_size = mid - left + 1;
    size_t sub2_size = right - mid;
    std::vector<int> sub1(sub1_size);
    std::vector<int> sub2(sub2_size);

    for (size_t i = 0; i < sub1_size; i++)
        sub1[i] = vec[left + i];

    for (size_t i = 0; i < sub2_size; i++)
        sub2[i] = vec[mid + 1 + i];   
    
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    
    while (i < sub1_size && j <sub2_size)
    {
        if (sub1[i] <= sub2[j])
        {
            vec[k] = sub1[i];
            i++;
        }
        else
        {
            vec[k] = sub2[j];
            j++;
        }
        k++;
    } 
    while (i < sub1_size)
    {
        vec[k] = sub1[i];
        i++;
        k++;
    }
    while (j < sub2_size)
    {
        vec[k] = sub2[j];
        j++;
        k++;
    }
}

void mergeInsertionSort(std::vector<int> &vec, size_t left, size_t right, size_t k)
{
    if (left < right)
    {
        if (right - left <= k)
            insertionSort(vec, left, right);
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(vec, left,  mid, k);
            mergeInsertionSort(vec, mid + 1, right, k);
            merge(vec, left, mid, right);
        }
    }
}

// void merge(std::list<int> &lst, size_t left, size_t mid, size_t right)
// {
//     size_t sub1_size = mid - left + 1;
//     size_t sub2_size = right - mid;
//     std::list<int> sub1(lst.begin(), std::next(lst.begin(), mid + 1));
//     std::list<int> sub2(std::next(lst.begin(), mid + 1), lst.end());
//     std::list<int>::iterator it_i = sub1.begin();
//     // for (std::list<int>::iterator it = sub1.begin(); it != sub1.end(); it++)
//     //     std::cout << *it << " ";
//     // for (std::list<int>::iterator it = sub2.begin(); it != sub2.end(); it++)
//     //     std::cout << *it << " ";
//     // for (size_t i = 0; i < sub1_size; i++)
//     // {
//     //     sub1.push_back(*it_i);
//     //     it_i++;
//     // }
        
//     // for (size_t i = 0; i < left; ++i)
//     //     ++it_i;

//     // for (size_t i = 0; i < sub2_size; i++)
//     // {
//     //     sub2.push_back(*it_i); 
//     //     it_i++;
//     // }
    
//     // it_i = sub1.begin();
//     std::list<int>::iterator it_j = sub2.begin();
//     lst.clear();
//     while (it_i != sub1.end() && it_j != sub2.end())
//     {
//         if (*it_i <= *it_j)
//         {
//             lst.push_back(*it_i);
//             it_i++;
//         }
//         else
//         {
//             lst.push_back(*it_j);
//             it_j++;
//         }
//     } 
//     while (it_i != sub1.end())
//     {
//         lst.push_back(*it_i);
//         it_i++;
//         // sub1.pop_front();
//     }
//     while (it_j != sub2.end())
//     {
//         lst.push_back(*it_j);
//         it_j++;
//         // sub2.pop_front();
//     }
// }


void merge(std::list<int> &lst, size_t left, size_t mid, size_t right)
{
    size_t sub1_size = mid - left + 1;
    size_t sub2_size = right - mid;
    std::list<int> sub1;
    std::list<int> sub2;
    std::list<int>::iterator it_i = lst.begin();
    for (size_t i = 0; i < sub1_size; i++)
    {
        sub1.push_back(*it_i);
        it_i++;
    }

    for (size_t i = 0; i < sub2_size; i++)
    {
        sub2.push_back(*it_i); 
        it_i++;
    }
    
    // for (std::list<int>::iterator it = sub2.begin(); it != sub2.end(); it++)
    //     std::cout << *it << " ";
    // for (std::list<int>::iterator it = sub1.begin(); it != sub1.end(); it++)
    //     std::cout << *it << " ";
    
    it_i = sub1.begin();
    std::list<int>::iterator it_j = sub2.begin();
    lst.clear();
    while (it_i != sub1.end() && it_j != sub2.end())
    {
        if (*it_i <= *it_j)
        {
            lst.push_back(*it_i);
            it_i++;
        }
        else
        {
            lst.push_back(*it_j);
            it_j++;
        }
    } 
    while (it_i != sub1.end())
    {
        lst.push_back(*it_i);
        it_i++;
    }
    while (it_j != sub2.end())
    {
        lst.push_back(*it_j);
        it_j++;
    }
}

void insertionSort(std::list<int> &lst)
{
    std::list<int>::iterator it_temp;
    // for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    //     std::cout << *it << " ";
    for (std::list<int>::iterator it_i = ++lst.begin(); it_i != lst.end(); ++it_i)
    {
        int key = *it_i;
        std::cout << key;
        std::list<int>::iterator it_j = it_i;
        --it_j; // Move to the previous element
        it_temp = it_j;
        ++it_temp;
        // Shift elements greater than key one position to the right
        while (it_j != lst.begin() && key < *it_j)
        {
            it_temp = it_j;
            ++it_temp;
            *it_temp = *it_j;
            --it_j;
        }

        // Assign the key value to the correct position
        // it_temp = it_j;
        // ++it_temp;
        *it_temp = key;
    }    
}



// void insertionSort(std::vector<int> &vec, size_t left, size_t right)
// {
//     for (size_t i = left + 1; i <= right; i++)
//     {
//         int key = vec[i];
//         size_t j = i - 1;
//         while (j >= left && key < vec[j])
//         {
//             vec[j + 1] = vec[j];
//             j--;
//         }
//         vec[j + 1] = key;
//     }    
// }

void mergeInsertionSort(std::list<int> &lst, size_t left, size_t right, size_t k)
{
    if (left < right)
    {
        if (right - left <= k)
            insertionSort(lst);
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(lst, left,  mid, k);
            mergeInsertionSort(lst, mid + 1, right, k);
            merge(lst, left, mid, right);
        }
    }
}