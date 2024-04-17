/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:24:27 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 13:40:16 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array &copy);
        unsigned int size() const;
        Array &operator=(const Array &rhs);
        T& operator[](unsigned int index);
};

template <typename T> 
Array<T>::Array() : _array(NULL), _size(0)
{}

template <typename T> 
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{}

template <typename T> 
Array<T>::~Array()
{
    if (_array)
        delete[] _array;
}

template <typename T> 
Array<T>::Array(const Array &copy) : _array(new T[copy.size()]), _size(copy.size())
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i];
}

template <typename T> 
Array<T>& Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] _array;
        _array = new T[rhs.size()];
        _size = rhs.size();
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = rhs._array[i];
    }
    return (*this);
}

template <typename T> 
unsigned int Array<T>::size() const
{
    return _size;
}

class indexOutRange : public std::exception
{
    virtual const char * what() const throw()  
    {  
        return "Index is out of range";
    }  
};

template <typename T> 
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw indexOutRange();
    return _array[index];
}
#endif