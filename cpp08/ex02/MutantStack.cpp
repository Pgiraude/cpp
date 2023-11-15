#include "MutantStack.hpp"


MutantStack::MutantStack(void) : _name("default")
{
	std::cout << "MutantStack VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

MutantStack::MutantStack(std::string name) : _name(name)
{
	if (name.empty())
		this->_name = "default";
	std::cout << "MutantStack STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

MutantStack::MutantStack(MutantStack const &copy) : _name(copy._name)
{
	std::cout << "MutantStack COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

MutantStack::~MutantStack(void)
{
	std::cout << "MutantStack VOID " << RED "destructor" RESET << " called" << std::endl;
}

MutantStack    &MutantStack::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		this->_name = rhs._name;
	std::cout << "MutantStack '=' " << YELLOW "assignement" RESET << " called" << std::endl;
	return (*this);
}

std::string	MutantStack::getName(void) const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &out, const MutantStack &i)
{
	out << "<< MutantStack name is " << i.getName() << std::endl;
	return (out);
}