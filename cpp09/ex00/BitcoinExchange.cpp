#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "BitcoinExchange VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
    (void)copy;
    std::cout << "BitcoinExchange COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange VOID " << RED "destructor" RESET << " called" << std::endl;
}

BitcoinExchange    &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    (void)rhs;
    std::cout << "BitcoinExchange '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}
