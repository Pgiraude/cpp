#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "-----------test n1 success execut------------" <<std::endl;
	{
		Bureaucrat A("Jean", 1);
		RobotomyRequestForm B("Dylan");
		ShrubberyCreationForm C("Logan");
		PresidentialPardonForm D("Mulan");
		std::cout << "----------------" << std::endl;
		A.executeForm(B);
		A.executeForm(C);
		A.executeForm(D);
		std::cout << "----------------" << std::endl;

	}
	std::cout << "-----------test n2 grade too low to execute------------" <<std::endl << std::endl;
	{
		Bureaucrat A("Jean", 150);
		RobotomyRequestForm B("Dylan");
		ShrubberyCreationForm C("Logan");
		PresidentialPardonForm D("Mulan");
		std::cout << "----------------" << std::endl;
		A.executeForm(B);
		A.executeForm(C);
		A.executeForm(D);
		std::cout << "----------------" << std::endl;
	}
	std::cout << "-----------test n3 could sign x2------------" << std::endl << std::endl;
	{
		Bureaucrat A("Arthur", 1);
		RobotomyRequestForm B("Dylan");
		ShrubberyCreationForm C("Logan");
		PresidentialPardonForm D("Mulan");
		std::cout << "----------------" << std::endl;
		A.signForm(B);
		A.signForm(C);
		A.signForm(D);
		std::cout << "----------------" << std::endl;
		A.signForm(B);
		A.signForm(C);
		A.signForm(D);
		std::cout << "----------------" << std::endl;
	}
	std::cout << "-----------test n4 couldn't sign------------" << std::endl << std::endl;
	{
		Bureaucrat A("Arthur", 150);
		RobotomyRequestForm B("Dylan");
		ShrubberyCreationForm C("Logan");
		PresidentialPardonForm D("Mulan");
		std::cout << "----------------" << std::endl;
		A.signForm(B);
		A.signForm(C);
		A.signForm(D);
		std::cout << "----------------" << std::endl;
	}
	std::cout << "-----------test n5 Form------------" << std::endl << std::endl;
	{
		Bureaucrat A("Arthur", 150);
		RobotomyRequestForm B;
		std::cout << "----------------" << std::endl;
		B.beSigned(A);
		std::cout << "----------------" << std::endl;
	}

}