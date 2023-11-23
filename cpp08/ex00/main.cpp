#include "easyfind.hpp"

int	main(void)
{
	std::cout << "--------- Test n1 easyfind vector---------" << std::endl << std::endl;
	{
		std::vector<int>	v1(2);
		v1.push_back(888);
		v1.push_back(999);
		easyfind(v1, 999);
		easyfind(v1, 3);
	}
	std::cout << "--------- Test n2 easyfind list---------" << std::endl << std::endl;
	{
		std::list<int>	l1;

		l1.push_back(888);
		l1.push_back(999);
		easyfind(l1, 999);
		easyfind(l1, 2);
	}
}
