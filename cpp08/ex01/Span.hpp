#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Span
{
    public:
        Span(unsigned int N);
        Span(Span const &copy);
        ~Span(void);
        //OPERATOR//
        Span	&operator=(Span const &rhs);
        //GETEUR//
        std::vector<int> const &getArray(void) const;
        //OTHER//
        void    addNumber(int nbr);
        void    addNumber(std::vector<int>::const_iterator &begin, std::vector<int>::const_iterator &end);
        void    fillArray(void);
        int     shortestSpan(void);
        int     longestSpan(void);

        //EXCEPTION//
        class	ArrayFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Array is full!" RESET);
				}
		};
        class	ArrayToSmall : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "Array is too small" RESET);
				}
		};    

    private:
        std::vector<int>           _array;
        unsigned int               _arraySize;
};

std::ostream    &operator<<(std::ostream &out, const Span &i);

#endif