#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

template<typename T>
class MutantStack
{
	public:
	typedef typename std::stack<T>::container_type::iterator	iterator;


		MutantStack(void);
		MutantStack(MutantStack const &copy);
		~MutantStack(void);

		MutantStack	&operator=(MutantStack const &rhs);


};

#endif