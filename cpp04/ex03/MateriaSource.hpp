#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class MateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(std::string name);
        MateriaSource(MateriaSource const &copy);
        ~MateriaSource(void);

        MateriaSource	&operator=(MateriaSource const &rhs);

        std::string	getName(void) const;

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

    private:
        std::string	_type;
        AMateria    *_book[4];
};

std::ostream    &operator<<(std::ostream &out, const MateriaSource &i);

#endif