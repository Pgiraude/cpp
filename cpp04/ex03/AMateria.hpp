#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class AMateria
{
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const & copy);
        ~AMateria(void);

        AMateria	&operator=(AMateria const & rhs);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

    protected:
        std::string	_type;
};

std::ostream    &operator<<(std::ostream &out, const AMateria &i);

#endif