#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &copy);
        ~PmergeMe(void);

        PmergeMe	&operator=(PmergeMe const &rhs);

};

#endif