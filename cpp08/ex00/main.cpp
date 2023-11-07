#include "easyfind.hpp"

int	main(void)
{
	std::list<int> lst;
	lst.push_back(10);
	lst.push_front(9);

	std::list<int>::const_iterator it;

	it = lst.begin();
	std::cout << *it << std::endl;
}
