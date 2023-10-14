#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &rsh);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &form);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "grade is too high!!" RESET);
				}
		};

		class	GradeToolowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (RED "grade is too low!!" RESET);
				}
		};

	private:

		const std::string	_name;
		int					_grade;
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &i);

#endif