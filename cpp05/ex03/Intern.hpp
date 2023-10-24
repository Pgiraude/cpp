#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Intern
{
    public:
        Intern(void);
        Intern(Intern const &copy);
        ~Intern(void);

        Intern	&operator=(Intern const &rhs);

        AForm   *presidential(std::string target);
        AForm   *robotomy(std::string target);
        AForm   *shrubbery(std::string target);

        AForm   *makeForm(std::string form, std::string target);

};

#endif