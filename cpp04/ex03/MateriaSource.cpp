#include "MateriaSource.hpp"


MateriaSource::MateriaSource(void) : _name("default")
{
    std::cout << "MateriaSource VOID " << GREEN "constructor" RESET << " called" << std::endl;
}


MateriaSource::MateriaSource(MateriaSource const &copy) : _name(copy._name)
{
    std::cout << "MateriaSource COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource VOID " << RED "destructor" RESET << " called" << std::endl;
}

MateriaSource    &MateriaSource::operator=(MateriaSource const &rhs)
{
    if (this != &rhs)
        this->_name = rhs._name;
    std::cout << "MateriaSource '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	MateriaSource::getName(void) const
{
    return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const MateriaSource &i)
{
    out << "<< MateriaSource name is " << i.getName() << std::endl;
    return (out);
}