#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &copy);
        ~Ice(void);

        Ice	&operator=(Ice const &rhs);
        AMateria* clone() const;
        void use(ICharacter& target);
        

};

std::ostream    &operator<<(std::ostream &out, const Ice &i);

#endif