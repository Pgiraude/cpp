#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void)
{
    std::cout << "PmergeMe VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
    (void)copy;
    std::cout << "PmergeMe COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

PmergeMe::~PmergeMe(void)
{
    std::cout << "PmergeMe VOID " << RED "destructor" RESET << " called" << std::endl;
}

PmergeMe    &PmergeMe::operator=(PmergeMe const &rhs)
{
    (void)rhs;
    std::cout << "PmergeMe '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}