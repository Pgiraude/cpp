#include "Span.hpp"


Span::Span(unsigned int N) : _arraySize(N)
{
    std::cout << "Span STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::Span(Span const &copy)
{
    *this = copy; //need good implementation of operator '='
    std::cout << "Span COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::~Span(void)
{
    std::cout << "Span VOID " << RED "destructor" RESET << " called" << std::endl;
}

Span    &Span::operator=(Span const &rhs)
{
    if (*_it < _array.size()) //need to change
        throw ("not good")
    else //copy array and other private elements

    std::cout << "Span '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}


std::ostream	&operator<<(std::ostream &out, const Span &i)
{
    out << "<< Span value are :" << std::endl;
    for (std::vector<unsigned int>::iterator it = _array.begin() ; it != _array.end(); it++)
        out << *it << ", ";
    return (out);
}