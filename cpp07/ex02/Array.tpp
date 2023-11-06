

#include "Array.hpp"

template <typename T>
Array< T >::Array(void) : _size(0)
{
    this->_elementsArray = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_elementsArray = new T[n];
}

template<typename T >
Array<T>::~Array(void)
{
    if (_elementsArray != NULL)
        delete [] _elementsArray;
}

template<typename T>
Array<T>::Array(Array const &copy)
{
    *this = copy;
}

template<typename T>
unsigned int    Array<T>::size(void) const
{
    return (_size);
}

template<typename T>
Array<T>   &Array<T>::operator=(Array const &rhs)
{
    if (_elementsArray != NULL)
        delete [] _elementsArray;
    this->_size = rhs._size;
    this->_elementsArray = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _elementsArray[i] = rhs._elementsArray[i];
    return (*this);
}

template<typename T>
T    &Array<T>::operator[](unsigned int idx)
{
    if (idx >= _size)
        throw (std::exception());
    else
        return(_elementsArray[idx]);
}


template<typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &i)
{
    if (i.size() == 0)
    {
        out << "Nothing in the Array of elements!" << std::endl;
    }
    else 
    {
        for (unsigned int idx = 0; idx < i.size(); idx++)
            out << "idx " << idx << " =[" << i[idx] << "] ";
        out << std::endl;
    }
    return (out);
}