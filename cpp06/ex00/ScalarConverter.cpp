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

void	ScalarConverter::printchar(std::string to_conv)
{
	std::stringstream ss;
	ss << to_conv;
	long int value;
	ss >> value;
	if (value >= 0 && value <= 127 && std::isgraph(value))
		std::cout << "char:\t" << static_cast <char>(value) << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
}

void	ScalarConverter::printint(std::string to_conv)
{
	if (to_conv.length() == 1)
	{
		std::cout << "int:\t" << static_cast <int>(to_conv[0]) << std::endl;
		return ;
	}
	long int	nbr;
	nbr = atoi(to_conv.c_str());

	std::cout << "int:\t" << static_cast<int>(nbr) << std::endl;

}

void	ScalarConverter::printfloat(std::string to_conv)
{
	std::stringstream ss;
	ss << to_conv;
	float value;
	ss >> value;

	std::cout << "float:\t" << value << ".0f" <<std::endl;

}

void	ScalarConverter::printdouble(std::string to_conv)
{
	std::stringstream ss(to_conv);
	double value;
	ss >> value;

	std::cout << "double:\t" << value << std::endl;

}
