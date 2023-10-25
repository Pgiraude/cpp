#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "-----------test n1 success intern------------" <<std::endl;
	{
		Intern A;
		AForm* rrf;

		std::cout << "----------------" << std::endl;
		rrf = A.makeForm("robotomy request", "Dylan");
		std::cout << "----------------" << std::endl;
		(void)rrf;
		delete rrf;
	}
	std::cout << "-----------test n2 failed intern------------" <<std::endl << std::endl;
	{
		Intern A;
		AForm* rrf;

		std::cout << "----------------" << std::endl;
		rrf = A.makeForm("random form", "Dylan");
		std::cout << "----------------" << std::endl;
		(void)rrf;
	}
	std::cout << "-----------test n3 create form and use it------------" << std::endl << std::endl;
	{
		Intern A;
		AForm* rrf;

		std::cout << "----------------" << std::endl;
		rrf = A.makeForm("presidential pardon", "Dylan");
		std::cout << "----------------" << std::endl;
		Bureaucrat B("Paul", 1);
		B.signForm(*rrf);
		std::cout << "----------------" << std::endl;
		Bureaucrat C("Jean", 2);
		C.executeForm(*rrf);
		std::cout << "----------------" << std::endl;
		delete rrf;
	}

}