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
		size_t				getJacobsthalNum(std::size_t n);

		// ---------------------- vector ---------------------
		std::vector<int>	splitPairContainer(std::vector< std::pair<int, int> > &pairVector);
		void				finalInsertionVector(int value);
		void				jackobsthalInsertionVector(std::vector<int> &pending);

		// ---------------------- list ---------------------
		std::list<int>		splitPairContainer(std::list< std::pair<int, int> > &pairVector);
		void				finalInsertionList(int value);
		void				jackobsthalInsertionList(std::list<int> &pending);

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &copy);
        ~PmergeMe(void);

        PmergeMe	&operator=(PmergeMe const &rhs);
		
		std::vector<int>	&getVector(void);
		std::list<int>		&getList(void);

        void mergeSort(std::vector<int> &Array);
        void mergeSort(std::list<int> &Array);

		void mergeInsertionSort(std::vector<int> &Array);
		void mergeInsertionSort(std::list<int> &Array);
		int	check_input(int argc, char **argv);
		void tester(int argc, char **argv);
		

        //-------------------- templates ------------------------

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
			if (container.size() >= 500000)
				throw PmergeMe::TooMuchValues();
        	return (0);
        }

        template <typename T>
        void	print_container(T & container)
        {
        	int idx = 0;
			int size = container.size();
        	for (typename T::iterator it = container.begin(); it != container.end(); it++)
        	{
        		idx++;
        		if (idx > 4 && size > 5)
        		{
        			std::cout << "[...]";
        			break;
        		}
        		std::cout << *it << " ";
        	}
        	std::cout << std::endl;
        }

		template <typename T>
		void	checkIfOddSize(T & container)
		{
			this->_isTale = false;
			if (container.size() % 2 != 0)
			{
				this->_isTale = true;
				this->_tale = container.back();
				container.pop_back();
			}
		}

		// ---------------------- Exceptions -----------------------

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
					return (RED "Error: " RESET "invalid input. Should be integers between [0;int_max]");
				}
		};

		class	MaxInt : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "values must be <= int_max");
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

		class	TooMuchValues : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (YELLOW "Warning: " RESET "too much values, try with 100000 values");
				}
		};

};

#endif