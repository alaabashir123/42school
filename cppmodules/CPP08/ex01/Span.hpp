/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:31:31 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 17:54:34 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <limits>

class Span
{
    private:
        std::list<int> _list;
        unsigned int _N;
    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &rhs);
        void addNumber(int x);
        void addNumbers(std::list<int>::const_iterator first, std::list<int>::const_iterator last);
        int shortestSpan();
        int longestSpan();
        void printSpan();
};

#endif