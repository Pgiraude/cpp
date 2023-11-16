#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void) : _name("default")
{
    std::cout << "BitcoinExchange VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string name) : _name(name)
{
    if (name.empty())
        this->_name = "default";
    std::cout << "BitcoinExchange STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _name(copy._name)
{
    std::cout << "BitcoinExchange COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange VOID " << RED "destructor" RESET << " called" << std::endl;
}

BitcoinExchange    &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
        this->_name = rhs._name;
    std::cout << "BitcoinExchange '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	BitcoinExchange::getName(void) const
{
    return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const BitcoinExchange &i)
{
    out << "<< BitcoinExchange name is " << i.getName() << std::endl;
    return (out);
}