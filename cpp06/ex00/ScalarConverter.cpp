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

int	CheckValideInput(std::string input)
{
	if (input.length() == 1)
		return (0);
	int i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (std::isdigit(input[i]) && input[i])
		i++;
	if (input[i] == '.' && input[i])
		i++;
	while (std::isdigit(input[i]) && input[i])
		i++;
	if (input[i] == 'f' && input[i])
		i++;
	if (input[i])
		return (1);
	else
		return (0);
}

void	ScalarConverter::printchar(std::string to_conv)
{
	if (to_conv.length() == 1)
	{
		std::cout << "char:\t" << static_cast <char>(to_conv[0]) << std::endl;
		return ;
	}
	std::stringstream ss;
	ss << to_conv;
	long int value;
	ss >> value;
	if (value >= 0 && value <= 127 && std::isgraph(value))
		std::cout << "char:\t" << static_cast <char>(value) << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\tImpossible" << std::endl;
}

void	ScalarConverter::printint(std::string to_conv)
{
	if (to_conv.length() == 1)
	{
		std::cout << "int:\t" << static_cast <int>(to_conv[0]) << std::endl;
		return ;
	}
	long int	nbr1;
	nbr1 = atoi(to_conv.c_str());
	long int	nbr2;
	nbr2 = atol(to_conv.c_str());
	if (nbr1 == nbr2)
		std::cout << "int:\t" << static_cast<int>(nbr1) << std::endl;
	else
		std::cout << "int:\tImpossible" << std::endl;
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

void	ScalarConverter::convert(std::string to_conv)
{
	if (CheckValideInput(to_conv) == 0)
	{
		printchar(to_conv);
		printint(to_conv);
		printfloat(to_conv);
		printdouble(to_conv);
	}
	else
	{
		std::cout << "char:\tImpossible" << std::endl;
		std::cout << "int:\tImpossible" << std::endl;
		if (to_conv == "+inf" || "inf" || "+inff" || "inff")
	}
}