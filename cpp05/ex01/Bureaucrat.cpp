#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150)
{
	std::cout << RED << _name << " DEFAULT Bureaucrat constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << RED << _name << " NAME GRADE Bureaucrat constructor called" RESET << std::endl;
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
	std::cout << RED << _name << " COPY Bureaucrat constructor called" RESET << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << _name << " Default Bureaucrat DESTRUCTOR called" RESET << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	std::cout << _name << " '=' OPERATOR Bureaucrat called" << std::endl;
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

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.getSignGrade() < _grade)
			throw (Bureaucrat::GradeToolowException());
		else if (_grade >= 1)
			form.setSigned();
	}
	catch(Bureaucrat::GradeToolowException &e)
	{
		std::cerr << RED "BURAUCRAT " << _name << RESET " couldn't signed" << BLUE " FORM " << form.getName() << RESET " because " << e.what() << '\n';
	}
}

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &i)
{
	out << RED " << BUREAUCRAT " << i.getName() << RESET << " is grade " << RED << i.getGrade() << RESET << std::endl;
	return out;
}
