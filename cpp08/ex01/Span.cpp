#include "Span.hpp"


Span::Span(unsigned int N) : _arraySize(N)
{
	// std::cout << "Span STRING " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::Span(Span const &copy)
{
	*this = copy;
	// std::cout << "Span COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

Span::~Span(void)
{
	// std::cout << "Span VOID " << RED "destructor" RESET << " called" << std::endl;
}

Span    &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_array.clear();
		_array.insert(_array.begin(), rhs._array.begin(), rhs._array.end());
		_arraySize = rhs._arraySize;
	}
	// std::cout << "Span '=' " << YELLOW "assignement" RESET << " called" << std::endl;
	return (*this);
}

std::vector<int> const	&Span::getArray(void) const
{
	return (_array);
}

void	Span::addNumber(int nbr)
{
	if (_arraySize == 0)
		throw(Span::ArrayToSmall());
	else if (_array.size() == _arraySize)
		throw(Span::ArrayFull());
	else
		_array.push_back(nbr);
}

void	Span::addNumber(std::vector<int>::const_iterator &begin, std::vector<int>::const_iterator &end)
{
	if (std::distance(begin, end) + _array.size() > _arraySize)
		throw(Span::ArrayToSmall());
	else if (begin == end)
		this->addNumber(*end);
	else
		_array.insert(_array.end(), begin, end);
}

void	Span::fillArray(void)
{
	if (_arraySize == 0)
	{
		throw(Span::ArrayToSmall());
		return ;
	}
	else if (_arraySize == _array.size())
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
	if (_array.size() < 2)
	{
		throw (Span::ArrayToSmall());
		return (0);
	}
	std::vector<int> copySorted(_array);
	std::sort (copySorted.begin(), copySorted.end());
	int	value = this->longestSpan();
	for (std::vector<int>::iterator it = copySorted.begin(); it != copySorted.end() - 1; it++)
	{
		if (*(it + 1) - *it < value)
			value = *(it + 1) - *it;
	}
	copySorted.clear();
	return (value);
}

int     Span::longestSpan(void)
{
	if (_array.size() < 2)
	{
		throw (Span::ArrayToSmall());
		return (0);
	}
	int	maxElement = *std::max_element(_array.begin(), _array.end());
	int minElement = *std::min_element(_array.begin(), _array.end());
	return (maxElement - minElement);
}

std::ostream	&operator<<(std::ostream &out, const Span &i)
{
	out << "<< Span value are :" << std::endl;
	for (std::vector<int>::const_iterator it = i.getArray().begin() ; it != i.getArray().end(); ++it)
		out << "[" << *it << "] ";
	out << std::endl;
	return (out);
}
