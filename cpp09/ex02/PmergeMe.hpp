#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <sstream>
#include <limits>
#include <vector>

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

        void mergeSort(std::vector<int> &Array);
        void mergeSort(std::list<int> &Array);

        //templates

        template <typename T>
        int fill_list(T & container, char **argv)
        {
        	std::stringstream ss;
        	for (int i = 0; argv[i]; i++)
        		ss << argv[i] << " ";
        	long int value;
        	while (ss >> value)
        	{
        		if (value < 0 || value > std::numeric_limits<int>::max())
        			return (3);
        		container.push_back(static_cast<int>(value));
        	}
        	return (0);
        }

        template <typename T>
        void	print_list(T & container)
        {
        	int idx = 0;
        	for (typename T::iterator it = container.begin(); it != container.end(); it++)
        	{
        		idx++;
        		if (idx > 4)
        		{
        			std::cout << "[...]";
        			break;
        		}
        		std::cout << *it << " ";
        	}
        	std::cout << std::endl;
        }

};

#endif