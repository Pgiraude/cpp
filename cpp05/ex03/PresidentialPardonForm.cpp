#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    if (target.empty())
        this->_target = "default";
    std::cout << "PresidentialPardonForm STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) :  AForm("PresidentialPardonForm", 25, 5), _target(copy._target)
{
    std::cout << "PresidentialPardonForm COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm VOID " << RED "destructor" RESET << " called" << std::endl;
}

PresidentialPardonForm    &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    std::cout << "PresidentialPardonForm '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    std::cout << RED "Bureaucrat " << executor.getName() << YELLOW " try to execute " BLUE << getName() << RESET <<std::endl;
    if (executor.getGrade() <= getExecGrade() && executor.getGrade() >= 1)
        std::cout << GREEN << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
    else
        throw (Bureaucrat::GradeToolowException());
}

std::ostream	&operator<<(std::ostream &out, const PresidentialPardonForm &i)
{
    out << "<< PresidentialPardonForm target is " << i.getTarget() << std::endl;
    return (out);
}