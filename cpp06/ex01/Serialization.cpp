#include "Serialization.hpp"


Serialization::Serialization(void)
{
    std::cout << "Serialization VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

Serialization::Serialization(Serialization const &copy)
{
    *this = copy;
    std::cout << "Serialization COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Serialization::~Serialization(void)
{
    std::cout << "Serialization VOID " << RED "destructor" RESET << " called" << std::endl;
}

Serialization    &Serialization::operator=(Serialization const &rhs)
{
    (void)rhs;
    std::cout << "Serialization '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

uintptr_t   Serialization::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
