#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "-----------test n1 signature------------" <<std::endl;
	{
		Bureaucrat A("Jean", 1);
		Form B;

		std::cout << B;

		A.signForm(B);
		std::cout << A;
		std::cout << B;
	}
	std::cout << "-----------test n2 can't sign------------" <<std::endl << std::endl;
	{
		Bureaucrat A("Jack", 100);
		Form B("choco", 60, 60);
		
		std::cout << B;
		A.signForm(B);
		std::cout << A;
		std::cout << B;
	}
	std::cout << "-----------test n3 just could sign------------" <<std::endl << std::endl;
	{
		Bureaucrat A("Paul", 60);
		Form B("choco", 60, 60);
		
		std::cout << B;
		A.signForm(B);
		std::cout << A;
		std::cout << B;
	}
}