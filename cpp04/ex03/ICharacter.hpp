#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class ICharacter
{
        virtual ~ICharacter() {};
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif