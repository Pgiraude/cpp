#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
}; 

std::ostream    &operator<<(std::ostream &out, const IMateriaSource &i);

#endif