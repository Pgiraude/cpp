#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <deque>
# include <vector>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack< T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type::iterator			iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator	const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator	reverse_iterator;

		MutantStack(void);
		MutantStack(MutantStack const &copy);
		~MutantStack(void);

		MutantStack	&operator=(MutantStack const &rhs);

		iterator	end(void);
		iterator	begin(void);

		const_iterator	end(void) const;
		const_iterator	begin(void) const;

		reverse_iterator	rend(void);
		reverse_iterator	rbegin(void);
};

#include "MutantStack.tpp"

#endif