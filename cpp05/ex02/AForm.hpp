#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const &copy);
		~AForm(void);
		AForm &operator=(AForm const &rhs);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		getSignature(void) const;

		void        beSigned(Bureaucrat const &worker);

	private:
		const std::string	_name;
		bool				_signature;
		const int			_sign_grade;
		const int			_exec_grade;


		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "grade is too high!!" RESET);
				}
		};

		class	GradeToolowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "grade is too low!!" RESET);
				}
		};

};

std::ostream    &operator<<(std::ostream &out, const AForm &i);


#endif