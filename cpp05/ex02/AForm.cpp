#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signature(0), _sign_grade(150), _exec_grade(150)
{
    std::cout << BLUE << _name << " DEFAULT AForm constructor called" RESET << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signature(copy._signature), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	std::cout << BLUE << _name << " COPY AForm constructor called" RESET << std::endl;
    *this = copy;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signature(0), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << BLUE << _name << " NAME GRADE AForm constructor called" RESET << std::endl;
    try
    {
        if (_sign_grade < 1)
            throw (AForm::GradeTooHighException());
        if (_sign_grade > 150)
            throw (AForm::GradeToolowException());
    }
    catch(AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(AForm::GradeToolowException &e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::~AForm(void)
{
	std::cout << BLUE << _name << " Default AForm DESTRUCTOR called" RESET << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << _name << " '=' OPERATOR AForm called" << std::endl;
    this->_signature = rhs.getSignature();
    return (*this);
}

std::string	AForm::getName(void) const
{
    return (this->_name);
}

int			AForm::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int			AForm::getExecGrade(void) const
{
    return (this->_exec_grade);
}

bool		AForm::getSignature(void) const
{
    return (this->_signature);
}

void        AForm::beSigned(Bureaucrat const &worker)
{
    if (_sign_grade < worker.getGrade())
		throw (AForm::GradeToolowException());
	else if (worker.getGrade() >= 1 && _signature == 1)
    {
		std::cout << RED "Buraucrat " << worker.getName() << RESET " could sign the "<< BLUE "AForm " << _name << RESET;
        std::cout << " but was already signed" << std::endl;
    }
    else if (worker.getGrade() >= 1 && _signature == 0)
    {
        std::cout << RED "Buraucrat " << worker.getName() << RESET " have succesfuly sign "<< BLUE "AForm " << _name << RESET;
        std::cout << std::endl;
        this->_signature = 1;
    }
}

std::ostream    &operator<<(std::ostream &out, const AForm &i)
{
	out << BLUE " << AForm " << i.getName() << RESET << " is signature grade is " << BLUE << i.getSignGrade() << RESET;
	out << " is exec grade is " << BLUE << i.getExecGrade() << RESET << " is sign status is " << BLUE << i.getSignature() << RESET << std::endl;
    return out;
}