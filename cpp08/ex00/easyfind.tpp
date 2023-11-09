#include "easyfind.hpp"

template<typename T>
int easyfind(T arg, int to_find)
{
    typename T::iterator it;
    for (it = arg.begin(); it != arg.end(); it++)
    {
        if (*it == to_find)
        {
            std::cout << GREEN "One occurence found of : [" << *it << "]" RESET << std::endl;
            return (1);
        }
    }
    std::cout << RED "Don't find any occurence of : [" << to_find << "]" RESET << std::endl;
    return 0;
}