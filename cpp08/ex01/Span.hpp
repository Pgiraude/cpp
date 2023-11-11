#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

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
        Span(void);
        Span(std::string name);
        Span(Span const &copy);
        ~Span(void);

        Span	&operator=(Span const &rhs);

        std::string	getName(void) const;

    private:
        std::string	_name;
};

std::ostream    &operator<<(std::ostream &out, const Span &i);

#endif