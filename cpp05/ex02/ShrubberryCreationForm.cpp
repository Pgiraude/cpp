
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    if (target.empty())
        this->_target = "default";
    std::cout << "ShrubberyCreationForm STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) :  AForm("ShrubberyCreationForm", 145, 137), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm VOID " << RED "destructor" RESET << " called" << std::endl;
}

ShrubberyCreationForm    &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        this->_target = rhs._target;
    std::cout << "ShrubberyCreationForm '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() <= getExecGrade() && executor.getGrade() >= 1)
    {
        std::string name_file = this->_target + "_shrubbery";
        std::ofstream file(name_file.c_str());
        file << "   @@" << std::endl;
        file << "  @@@@" << std::endl;
        file << " @@@@@@" << std::endl;
        file << " @@@@@@" << std::endl;
        file << "  @@@@" << std::endl;
        file << " @ ||" << std::endl;
        file << "  \\||" << std::endl;
        file << " -----" << std::endl;
        std::cout << this->_target << " has create an ASCII tree" << std::endl;

    }
    else
        throw (Bureaucrat::GradeToolowException());
		
}

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &i)
{
    out << "<< ShrubberyCreationForm target is " << i.getTarget() << std::endl;
    return (out);
}