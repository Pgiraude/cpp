#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"


template < typename T>
T const	&max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template < typename T>
T const	&min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template < typename T>
void    swap(T &x, T &y)
{
	T   tmp;
	tmp = x;
	x = y;
	y = tmp;
}

#endif