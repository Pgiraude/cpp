

#include "Array.hpp"

template <typename T>
Array< T >::Array(void) : _elements(NULL), _size(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_elements = new T[n];
}

template<typename T >
Array<T>::~Array(void)
{

}

template<typename T>
Array<T>::Array(Array const &copy)
{
    (void)copy;
}

template<typename T>
T    &Array<T>::operator[](int idx)
{
    // if (idx >= _size)
    //     return ();
    // else
        return(_elements[idx]);
}

// template<typename T>
// std::ostream &operator<<(std::ostream &out, Array &rhs)
// {

// }