#include "Span.hpp"


Span::Span(void) : _name("default")
{
    std::cout << "Span VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::Span(std::string name) : _name(name)
{
    if (name.empty())
        this->_name = "default";
    std::cout << "Span STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::Span(Span const &copy) : _name(copy._name)
{
    std::cout << "Span COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::~Span(void)
{
    std::cout << "Span VOID " << RED "destructor" RESET << " called" << std::endl;
}

Span    &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
        this->_name = rhs._name;
    std::cout << "Span '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	Span::getName(void) const
{
    return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const Span &i)
{
    out << "<< Span name is " << i.getName() << std::endl;
    return (out);
}