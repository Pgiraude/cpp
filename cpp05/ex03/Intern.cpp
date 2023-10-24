#include "Intern.hpp"


Intern::Intern(void)
{
    std::cout << "Intern VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
    std::cout << "Intern COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern VOID " << RED "destructor" RESET << " called" << std::endl;
}

Intern    &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    std::cout << "Intern '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

AForm   *Intern::presidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::robotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::shrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm   *Intern::makeForm(std::string form, std::string target)
{
    std::string FormNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *FormList[3] = {Intern::presidential(target), Intern::robotomy(target), Intern::shrubbery(target)};
    for (int i = 0; i < 3; i++)
    {
        if (form == FormNames[i])
        {
            std::cout << GREEN "Intern has create form " << form << RESET << std::endl;
            return (FormList[i]);
        }
    }
    std::cerr << RED "Intern failed create form " << form << " Because he don't exist" RESET << std::endl;
    return (NULL);
}
