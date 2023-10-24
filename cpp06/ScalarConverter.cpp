#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(void) : _name("default")
{
    std::cout << "ScalarConverter VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string name) : _name(name)
{
    if (name.empty())
        this->_name = "default";
    std::cout << "ScalarConverter STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) : _name(copy._name)
{
    std::cout << "ScalarConverter COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter VOID " << RED "destructor" RESET << " called" << std::endl;
}

ScalarConverter    &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    if (this != &rhs)
        this->_name = rhs._name;
    std::cout << "ScalarConverter '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	ScalarConverter::getName(void) const
{
    return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const ScalarConverter &i)
{
    out << "<< ScalarConverter name is " << i.getName() << std::endl;
    return (out);
}