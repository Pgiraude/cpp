#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"
#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

        std::string	getTarget(void) const;

        void    execute(Bureaucrat const & executor) const;

    private:
        std::string	_target;
};

std::ostream    &operator<<(std::ostream &out, const RobotomyRequestForm &i);

#endif