#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>
#include <limits>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class RPN
{
    public:
        RPN(void);
        RPN(RPN const &copy);
        ~RPN(void);

        RPN	&operator=(RPN const &rhs);

        void    processing(char *input);

        // EXCEPTIONS //

        class	NotDigit : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "not a digit");
				}
		};

        class	Limits : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "final result or value must be included in ]min_int;max_int[");
				}
		};

        class	Error : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "bad input");
				}
		};

		class	DivideByZero : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "Error: " RESET "can't divide by zero");
				}
		};
};


#endif