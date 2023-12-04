#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

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


};


#endif