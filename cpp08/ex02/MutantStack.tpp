#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &copy) : std::stack<T, Container>(copy)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template<typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
		std::stack<T, Container>::operator=(rhs);
	return (*this);
}

//         ITERATOR

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::begin(void)
{
	return (std::stack<T, Container>::c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator    MutantStack<T, Container>::end(void)
{
	return (std::stack<T, Container>::c.end());
}

//         CONST_ITERATOR

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator    MutantStack<T, Container>::begin(void) const
{
	return (std::stack<T, Container>::c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator    MutantStack<T, Container>::end(void) const
{
	return (std::stack<T, Container>::c.end());
}

//         REVERSE_ITERATOR

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator    MutantStack<T, Container>::rbegin(void)
{
	return (std::stack<T, Container>::c.rbegin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator    MutantStack<T, Container>::rend(void)
{
	return (std::stack<T, Container>::c.rend());
}