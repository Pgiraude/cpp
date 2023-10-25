#include "Intern.hpp"


Intern::Intern(void)
{
    std::cout << "Intern VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
    (void)copy;
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

AForm   *Intern::makeForm(std::string form_name, std::string target)
{
    t_FormList formlist[3] = {
        {"presidential pardon", &Intern::presidential},
        {"robotomy request", &Intern::robotomy},
        {"shrubbery creation", &Intern::shrubbery}};
    
    for (int i = 0; i < 3; i++)
    {
        if (form_name == formlist[i].FormName)
        {
            std::cout << GREEN "Intern has create form " << form_name << RESET << std::endl;
            return ((this->*formlist[i].function)(target));
        }
    }
    std::cerr << RED "Intern failed create form " << form_name << " Because he don't exist" RESET << std::endl;
    return (NULL);
}
