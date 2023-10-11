#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "DEFAULT constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	std::cout << "COPY constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default DESTRUCTOR called" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}