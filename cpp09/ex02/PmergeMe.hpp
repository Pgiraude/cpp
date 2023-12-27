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
	private:
		std::vector<int>	_sortVector;
		std::list<int>		_sortList;
		bool				_isTale;
		int					_tale;

		void	checkIfOddSize(std::vector<int> &Array);

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &copy);
        ~PmergeMe(void);

        PmergeMe	&operator=(PmergeMe const &rhs);

        void mergeSort(std::vector<int> &Array);
        void mergeSort(std::list<int> &Array);

		void mergeInsertionSort(std::vector<int> &Array);

        //templates

        template <typename T>
        int fill_container(T & container, char **argv)
        {
        	std::stringstream ss;
        	for (int i = 0; argv[i]; i++)
        		ss << argv[i] << " ";
        	long int value;
        	while (ss >> value)
        	{
        		if (value < 0 || value > std::numeric_limits<int>::max())
        			throw PmergeMe::MaxInt();
        		container.push_back(static_cast<int>(value));
        	}
			if (container.empty())
				throw PmergeMe::EmptyContainer();
        	return (0);
        }

        template <typename T>
        void	print_container(T & container)
        {
        	int idx = 0;
			// int size = container.size();
        	for (typename T::iterator it = container.begin(); it != container.end(); it++)
        	{
        		idx++;
        		// if (idx > 4 && size > 5)
        		// {
        		// 	std::cout << "[...]";
        		// 	break;
        		// }
        		std::cout << *it << " ";
        	}
        	std::cout << std::endl;
        }

		// Exception

		class	NotEnoughArguments : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "need at least one argument");
				}
		};

		class	InvalidInput : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "invalid input. Should be a number > 0 and < intmax ");
				}
		};

		class	MaxInt : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "number > max int");
				}
		};

		class	EmptyContainer : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "no value input");
				}
		};

};

#endif