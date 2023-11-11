#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

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

        Span	&operator=(Span const &rhs);

        class	ArrayFull : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Array is full!" RESET);
				}
		};    

    private:
        std::vector<unsigned int>           _array;
        unsigned int                        _arraySize;
        std::vector<unsigned int>::iterator _it;
};

std::ostream    &operator<<(std::ostream &out, const Span &i);

#endif