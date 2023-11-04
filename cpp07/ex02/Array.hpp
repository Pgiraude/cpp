#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

template < typename T >
class Array
{
    public:
        Array< T >(void);
        Array< T >(T name);
        Array< T >(Array const &copy);
        ~Array< T >(void);

        Array	&operator=(Array const &rhs);

        std::string	getName(void) const;

    private:
        std::string	_name;
};

std::ostream    &operator<<(std::ostream &out, const Array &i);

#endif