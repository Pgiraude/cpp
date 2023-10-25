#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	(void)copy;
	std::cout << "ScalarConverter COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter VOID " << RED "destructor" RESET << " called" << std::endl;
}

ScalarConverter    &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	std::cout << "ScalarConverter '=' " << YELLOW "assignement" RESET << " called" << std::endl;
	return (*this);
}

void	ScalarConverter::printint(std::string to_conv)
{
	int	nbr;
	if (to_conv.length() == 1)
	{
		std::cout << "ScalarConverter conv string to int A" << static_cast <int>(to_conv[0]) << std::endl;
		return ;
	}
	nbr = atoi(to_conv.c_str());

	std::cout << "ScalarConverter conv string to int " << nbr << std::endl;

}

void	ScalarConverter::printdouble(std::string to_conv)
{
	std::stringstream ss(to_conv);
	double test;
	ss >> test;

	std::cout << "ScalarConverter conv string to double " << test << std::endl;

}