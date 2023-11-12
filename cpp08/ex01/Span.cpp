#include "Span.hpp"


Span::Span(unsigned int N) : _arraySize(N)
{
	std::cout << "Span STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::Span(Span const &copy)
{
	*this = copy;
	std::cout << "Span COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span VOID " << RED "destructor" RESET << " called" << std::endl;
}

Span    &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_array.clear();
		_array.insert(_array.begin(), rhs._array.begin(), rhs._array.end());
		_arraySize = rhs._arraySize;
	}
	std::cout << "Span '=' " << YELLOW "assignement" RESET << " called" << std::endl;
	return (*this);
}

std::vector<unsigned int>	Span::getArray(void) const
{
	return (_array);
}

void	Span::addNumber(int nbr)
{
	if (_array.size() == _arraySize)
		throw(ArrayFull::exception());
	else
		_array.push_back(nbr);
}


std::ostream	&operator<<(std::ostream &out, const Span &i)
{
	out << "<< Span value are :" << std::endl;
	for (std::vector<unsigned int>::iterator it = i.getArray().begin() ; it != i.getArray().end(); it++)
		out << "[" << *it << "], ";
	return (out);
}