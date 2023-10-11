#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150)
{
	std::cout << _name << " DEFAULT constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << _name << " NAME GRADE constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeToolowException());
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (Bureaucrat::GradeToolowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << _name << " COPY constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << _name << " Default DESTRUCTOR called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	std::cout << _name << " '=' OPERATOR called" << std::endl;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade <= 1)
			throw (Bureaucrat::GradeTooHighException());
		else
			this->_grade--;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Bureaucrat " << this->getName() << " is up to grade " << this->getGrade() << " now" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade >= 150){
			throw (Bureaucrat::GradeToolowException());
		}
		else{
			this->_grade++;
		}
	}
	catch(Bureaucrat::GradeToolowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Bureaucrat " << this->getName() << " is down to grade " << this->getGrade() << " now" << std::endl;
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &i)
{
	out << "Bureaucrat " << i.getName() << " is grade " << i.getGrade() << std::endl;
	return out;
}
