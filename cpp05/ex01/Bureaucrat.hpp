#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too high!!");
				}
		};

		class	GradeToolowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade is too low!!");
				}
		};

	private:

		const std::string	_name;
		int					_grade;
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &i);

#endif