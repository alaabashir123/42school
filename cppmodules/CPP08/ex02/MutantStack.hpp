/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:51:36 by abashir           #+#    #+#             */
/*   Updated: 2024/04/18 12:43:37 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <algorithm>
#include <iostream>
#include <list>


template <typename T>
class	MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &copy) {*this = copy;}
        MutantStack &operator=(const MutantStack &rhs)
        {
            if (this != &rhs)
		        std::stack<T, std::deque<T> >::operator=(rhs);
	        return (*this);
        }

        iterator	begin() {return (this->c.begin());}
        iterator	end() {return (this->c.end());}
        const_iterator	begin() const {return (this->c.begin());}
        const_iterator	end() const {return (this->c.end());}
};

#endif