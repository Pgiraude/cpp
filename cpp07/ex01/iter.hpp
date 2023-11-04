#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

template <typename A, typename L, typename F>
void	iter(A *adress, L const &length, F (*function)(A&))
{
	for (L i = 0; i < length; i++)
		function(adress[i]);
}

#endif