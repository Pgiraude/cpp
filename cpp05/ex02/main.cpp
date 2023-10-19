#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "-----------test n1 signature------------" <<std::endl;
	{
		Bureaucrat A("Jean", 1);
		RobotomyRequestForm B("Dylan");

		A.executeForm(B);

	}
	std::cout << "-----------test n2 can't sign------------" <<std::endl << std::endl;
	{
		
	}
	std::cout << "-----------test n3 just could sign------------" << std::endl << std::endl;
	{

	}
	std::cout << "-----------test n4 just could sign------------" << std::endl << std::endl;
	{
		
	}
}