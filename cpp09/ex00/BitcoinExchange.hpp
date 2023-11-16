#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string name);
        BitcoinExchange(BitcoinExchange const &copy);
        ~BitcoinExchange(void);

        BitcoinExchange	&operator=(BitcoinExchange const &rhs);

        std::string	getName(void) const;

    private:
        std::string	_name;
};

std::ostream    &operator<<(std::ostream &out, const BitcoinExchange &i);

#endif