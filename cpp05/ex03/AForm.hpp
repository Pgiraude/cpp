#ifndef AFORM_HPP
# define AFORM_HPP

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
		virtual ~AForm(void) = 0;
		AForm &operator=(AForm const &rhs);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		bool		getSignature(void) const;

		void        beSigned(Bureaucrat const &worker);

        virtual void    execute(Bureaucrat const & executor) const = 0;


		class	SignGradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "sign FORM grade is too high!!" RESET);
				}
		};

		class	SignGradeToolowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "sign FORM grade is too low!!" RESET);
				}
		};

		class	ExecGradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "exec FORM grade is too high!!" RESET);
				}
		};

		class	ExecGradeToolowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return (BLUE "exec FORM grade is too low!!" RESET);
				}
		};

	private:
		const std::string	_name;
		bool				_signature;
		const int			_sign_grade;
		const int			_exec_grade;


};

std::ostream    &operator<<(std::ostream &out, const AForm &i);


#endif