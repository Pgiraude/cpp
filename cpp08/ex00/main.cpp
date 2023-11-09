#include "easyfind.hpp"

int	main(void)
{
	{
		std::list<int> lst;
		lst.push_back(10);
		lst.push_front(9);
		lst.push_back(444);

		std::list<int>::const_iterator it;

		for (it = lst.begin(); it != lst.end(); it++)
			std::cout << *it << std::endl;

		std::map<std::string, int> map1;
		map1["lol"] = 14;
		std::cout << map1["aaaaaaa"] << std::endl;

		std::cout << "-----------" << std::endl;

		std::vector<int>	v1(2);
		v1.push_back(888);
		v1.push_back(999);
		for (long unsigned int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << std::endl;
		int *ptr = v1.data();
		std::cout << "-----------" << std::endl;

		std::cout << *(ptr + 2)<< std::endl;
	}
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
