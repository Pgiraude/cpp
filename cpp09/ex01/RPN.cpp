#include "RPN.hpp"


RPN::RPN(void)
{
    std::cout << "RPN VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

RPN::RPN(RPN const &copy)
{
    (void)copy;
    std::cout << "RPN COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

RPN::~RPN(void)
{
    std::cout << "RPN VOID " << RED "destructor" RESET << " called" << std::endl;
}

RPN    &RPN::operator=(RPN const &rhs)
{
    (void)rhs;
    std::cout << "RPN '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}
