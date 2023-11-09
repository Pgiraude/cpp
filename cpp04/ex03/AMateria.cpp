#include "AMateria.hpp"


AMateria::AMateria(void) : _type("default")
{
    std::cout << "AMateria VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    if (_type.empty())
        this->_type = "default";
    std::cout << "AMateria STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

AMateria::AMateria(AMateria const &copy) : _type(copy._type)
{
    std::cout << "AMateria COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria VOID " << RED "destructor" RESET << " called" << std::endl;
}

AMateria    &AMateria::operator=(AMateria const &rhs)
{
    if (this != &rhs)
        this->_type = rhs._type;
    std::cout << "AMateria '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string const &	AMateria::getType(void) const
{
    return (this->_type);
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "UNKNOWON" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const AMateria &i)
{
    out << "<< AMateria _type is " << i.getType() << std::endl;
    return (out);
}