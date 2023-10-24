#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class ScalarConverter
{
    public:
        ScalarConverter(void);
        ScalarConverter(std::string name);
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter(void);

        ScalarConverter	&operator=(ScalarConverter const &rhs);

        std::string	getName(void) const;

    private:
        std::string	_name;
};

std::ostream    &operator<<(std::ostream &out, const ScalarConverter &i);

#endif