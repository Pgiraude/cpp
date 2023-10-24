#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    if (target.empty())
        this->_target = "default";
    std::cout << "RobotomyRequestForm STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) :  AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
    std::cout << "RobotomyRequestForm COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm VOID " << RED "destructor" RESET << " called" << std::endl;
}

RobotomyRequestForm    &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    std::cout << "RobotomyRequestForm '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::cout << RED "Bureaucrat " << executor.getName() << YELLOW " try to execute " BLUE << getName() << RESET <<std::endl;
    if (executor.getGrade() <= getExecGrade() && executor.getGrade() >= 1)
    {
        std::cout << YELLOW "Drrrrriiiiiiillllllll!!" RESET << std::endl;
        srand(time(NULL));
        if ((rand() % 2) == 0)
            std::cout << GREEN << this->_target << " has been robotomized successfully" RESET << std::endl;
        else
            std::cout << RED << this->_target << " robotomy failed" RESET << std::endl;
    }
    else
        throw (Bureaucrat::GradeToolowException());
}

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &i)
{
    out << "<< RobotomyRequestForm target is " << i.getTarget() << std::endl;
    return (out);
}