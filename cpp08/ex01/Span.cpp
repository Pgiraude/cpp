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

std::vector<int> const	&Span::getArray(void) const
{
	return (_array);
}

void	Span::addNumber(int nbr)
{
	if (_array.size() == _arraySize)
		throw(Span::ArrayFull());
	else
		_array.push_back(nbr);
}

void	Span::fillArray(void)
{
	if (_arraySize == _array.size())
	{
		throw(Span::ArrayFull());
		return ;
	}
	srand(time(NULL));
	for (unsigned int i = _array.size(); i < _arraySize; i++)
		_array.push_back(rand());
}

int     Span::shortestSpan(void)
{

}

int     Span::longestSpan(void)
{
	std::max_element;
	std::min_element;
}

std::ostream	&operator<<(std::ostream &out, const Span &i)
{
	out << "<< Span value are :" << std::endl;
	for (std::vector<int>::const_iterator it = i.getArray().begin() ; it != i.getArray().end(); ++it)
		out << "[" << *it << "] ";
	out << std::endl;
	return (out);
}