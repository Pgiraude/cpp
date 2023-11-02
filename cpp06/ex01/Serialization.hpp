#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <stdint.h>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

typedef struct Data
{
    int         age;
    std::string name;
    char        sport[20];

}Data;

class Serialization
{
    public:
        Serialization(void);
        Serialization(Serialization const &copy);
        ~Serialization(void);

        Serialization	&operator=(Serialization const &rhs);

        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t ok);
};

#endif