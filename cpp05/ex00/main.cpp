#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "-----------test n1 increment but max------------" <<std::endl;
	{
		Bureaucrat A("jean", 1);

		A.incrementGrade();
		std::cout << A;
	}
	std::cout << "-----------test n2 decrement but min------------" <<std::endl << std::endl;
	{
		Bureaucrat A("Paul", 150);

		A.decrementGrade();
		std::cout << A;
	}
	std::cout << "-----------test n3 increment------------" <<std::endl << std::endl;
	{
		Bureaucrat A;

		A.incrementGrade();
		std::cout << A;
	}
	std::cout << "-----------test n4 wrong grade------------" <<std::endl << std::endl;
	{
		Bureaucrat A("bob", 458);

		A.incrementGrade();

		
	}

}