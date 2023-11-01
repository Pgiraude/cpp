#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <sstream>
# include <limits>

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
        ScalarConverter(ScalarConverter const &copy);
        ~ScalarConverter(void);

        ScalarConverter	&operator=(ScalarConverter const &rhs);

        static void convert(std::string to_conv);

        static void printchar(std::string to_conv);
        static void printint(std::string to_conv);
        static void printfloat(std::string to_conv);
        static void printdouble(std::string to_conv);

    private:
};

#endif