/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:44:30 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 17:55:45 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class listIsFull : public std::exception
{
    virtual const char * what() const throw()  
    {  
        return "The list is full";
    }  
};

class TooShort : public std::exception
{
    virtual const char * what() const throw()  
    {  
        return "The list doesn't have enough elements";
    }  
};

Span::Span(unsigned int N) : _N(N)
{}

Span::~Span()
{}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs._N;
        this->_list = rhs._list;
    }
    return (*this);
}

void Span::addNumber(int x)
{
    if (_list.size() >= _N)
        throw listIsFull();
    _list.push_back(x);
}

int Span::shortestSpan()
{
    if (_list.size() < 2)
        throw TooShort();
    
    int tmp = std::numeric_limits<int>::max();

    std::list<int> copy = _list;
    copy.sort();
    std::list<int>::const_iterator it = copy.begin();
    std::list<int>::const_iterator next = it;
    next++;
    while (next != copy.end())
    {
        int diff = *next - *it;
        if (diff < tmp)
            tmp = diff;
        ++it;
        ++next;
    }
    return tmp;
}


int Span::longestSpan()
{
    if (_list.size() < 2)
        throw TooShort();
    return (*std::max_element( _list.begin(), _list.end() ) - *std::min_element( _list.begin(), _list.end() ));    
}

void Span::addNumbers(std::list<int>::const_iterator first, std::list<int>::const_iterator last)
{
    while (first != last) 
    {
        addNumber(*first);
        ++first;
    }
}
void Span::printSpan()
{
    std::list<int>::const_iterator it;
    std::list<int>::const_iterator ite;

    ite = _list.end();

    for (it = _list.begin(); it != ite; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}