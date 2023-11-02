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
		return (1);
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
		return (0);
	else
		return (1);
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
	if (to_conv.length() == 1)
	{
		std::cout << "float:\t" << static_cast <float>(to_conv[0]) << ".0f" << std::endl;
		return ;
	}
	std::stringstream ss;
	ss << to_conv;
	float			value;
	ss >> value;
	ss.clear();

	ss.str(to_conv);
	long long int	tmp;
	ss >> tmp;
	float			round_nbr;
	round_nbr = static_cast <float>(tmp);

	ss.clear();
	ss << value;
	std::string	str_value;
	str_value = ss.str();

	if (value - round_nbr == 0 && str_value.find('e') == std::string::npos && str_value.find('E') == std::string::npos)
		std::cout << "float:\t" << value << ".0f" <<std::endl;
	else
		std::cout << "float:\t" << value << "f" <<std::endl;

}

void	ScalarConverter::printdouble(std::string to_conv)
{
	if (to_conv.length() == 1)
	{
		std::cout << "double:\t" << static_cast <double>(to_conv[0])<< ".0" << std::endl;
		return ;
	}
	std::stringstream ss(to_conv);
	double value;
	ss >> value;
	ss.clear();

	ss.str(to_conv);
	long long int	tmp;
	ss >> tmp;
	double			round_nbr;
	round_nbr = static_cast <double>(tmp);
	if (value - round_nbr == 0)
		std::cout << "double:\t" << value << ".0" << std::endl;
	else
		std::cout << "double:\t" << value << std::endl;
}

void	ScalarConverter::convert(std::string to_conv)
{
	if (CheckValideInput(to_conv))
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
		if (to_conv == "+inf" || to_conv == "inf" || to_conv == "+inff" || to_conv == "inff")
		{
			std::cout << "float:\t" << std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double:\t" << std::numeric_limits<double>::infinity() << std::endl;
		}
		else if (to_conv == "-inf" || to_conv == "-inff")
		{
			std::cout << "float:\t" << -1 * std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double:\t" << -1 * std::numeric_limits<double>::infinity() << std::endl;
		}
		else if (to_conv == "nan" || to_conv == "nanf")
		{
			std::cout << "float:\t" << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
			std::cout << "double:\t" << std::numeric_limits<double>::quiet_NaN() << std::endl;
		}
		else
		{
			std::cout << "float:\tImpossible" << std::endl;
			std::cout << "double:\tImpossible" << std::endl;
		}
	}
}