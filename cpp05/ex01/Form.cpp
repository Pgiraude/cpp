#include "Form.hpp"

Form::Form(void) : _name("default"), _signature(0), _sign_grade(150), _exec_grade(150)
{
    std::cout << BLUE << _name << " DEFAULT Form constructor called" RESET << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name), _signature(copy._signature), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	std::cout << BLUE << _name << " COPY Form constructor called" RESET << std::endl;
    *this = copy;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signature(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << BLUE << _name << " NAME GRADE Form constructor called" RESET << std::endl;
    try
    {
        if (_sign_grade < 1)
            throw (Form::GradeTooHighException());
        if (_sign_grade > 150)
            throw (Form::GradeToolowException());
    }
    catch(Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Form::GradeToolowException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::~Form(void)
{
	std::cout << BLUE << _name << " Default Form DESTRUCTOR called" RESET << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << _name << " '=' OPERATOR Form called" << std::endl;
    this->_signature = rhs.getSignature();
    return (*this);
}

std::string	Form::getName(void) const
{
    return (this->_name);
}

int			Form::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int			Form::getExecGrade(void) const
{
    return (this->_exec_grade);
}

bool		Form::getSignature(void) const
{
    return (this->_signature);
}

void        Form::beSigned(Bureaucrat const &worker)
{
    if (_sign_grade < worker.getGrade())
		throw (Form::GradeToolowException());
	else if (worker.getGrade() >= 1 && _signature == 1)
    {
		std::cout << RED "Buraucrat " << worker.getName() << RESET " could sign the "<< BLUE "FORM " << _name << RESET;
        std::cout << " but was already signed" << std::endl;
    }
    else if (worker.getGrade() >= 1 && _signature == 0)
    {
        std::cout << RED "Buraucrat " << worker.getName() << RESET " have succesfuly sign "<< BLUE "FORM " << _name << RESET;
        std::cout << std::endl;
        this->_signature = 1;
    }
}

std::ostream    &operator<<(std::ostream &out, const Form &i)
{
	out << BLUE " << FORM " << i.getName() << RESET << " is signature grade is " << BLUE << i.getSignGrade() << RESET;
	out << " is exec grade is " << BLUE << i.getExecGrade() << RESET << " is sign status is " << BLUE << i.getSignature() << RESET << std::endl;
    return out;
}