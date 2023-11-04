#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

template < typename T >
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &copy);
		~Array(void);

		Array	&operator=(Array const &rhs);
		T	&operator[](int idx);

		int	size(void) const;

	private:
		T				*_elements;
		unsigned int	_size;
};

template < typename T >
std::ostream    &operator<<(std::ostream &out, const Array<T> &i);

# include "Array.tpp"

#endif