#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
# include "ICharacter.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(Character const &copy);
        ~Character(void);

        Character	&operator=(Character const &rhs);

        std::string	const &getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string	_name;
};

std::ostream    &operator<<(std::ostream &out, const Character &i);

#endif