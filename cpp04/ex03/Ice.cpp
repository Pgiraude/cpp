#include "Ice.hpp"


Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
    *this = copy;
    std::cout << "Ice COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "Ice VOID " << RED "destructor" RESET << " called" << std::endl;
}

Ice    &Ice::operator=(Ice const &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "Ice '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

AMateria *  Ice::clone(void) const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Ice &i)
{
    out << "<< Ice name is " << i.getType() << std::endl;
    return (out);
}