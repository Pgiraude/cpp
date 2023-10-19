
#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class ShrubberryCreationForm : public AForm
{
    public:
        ShrubberryCreationForm(void);
        ShrubberryCreationForm(std::string target);
        ShrubberryCreationForm(ShrubberryCreationForm const &copy);
        ~ShrubberryCreationForm(void);

        ShrubberryCreationForm	&operator=(ShrubberryCreationForm const &rhs);

        std::string	getTarget(void) const;

    private:
        std::string	_target;
};

std::ostream    &operator<<(std::ostream &out, const ShrubberryCreationForm &i);

#endif