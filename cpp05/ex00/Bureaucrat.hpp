#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &rsh);

		std::string	getName(void) const;
		int			getGrade(void) const;

	private:

		const std::string	_name;
		int					_grade;
};

#endif