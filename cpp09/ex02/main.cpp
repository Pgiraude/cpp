#include "PmergeMe.hpp"

// int fill_list(std::list<int> &list, char **argv)
// {
// 	std::stringstream ss;
// 	for (int i = 0; argv[i]; i++)
// 		ss << argv[i] << " ";
// 	long int value;
// 	while (ss >> value)
// 	{
// 		if (value < 0 || value > std::numeric_limits<int>::max())
// 			return (3);
// 		list.push_back(static_cast<int>(value));
// 	}
// 	return (0);
// }

// void	print_list(std::list<int> &list)
// {
// 	int idx = 0;
// 	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
// 	{
// 		idx++;
// 		if (idx > 4)
// 		{
// 			std::cout << "[...]";
// 			break;
// 		}
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }





int main(int argc, char **argv)
{
	PmergeMe A;

	if (argc < 2)
		return (1);

	for (int idx = 1; idx < argc; idx++)
		for (int i = 0; argv[idx][i]; i++)
			if (!isdigit(argv[idx][i]) && !isblank(argv[idx][i]))
				return (2);
	
	std::list<int> listA;
	if (A.fill_list(listA, argv + 1) != 0)
		return (3);
	listA.sort();


	std::vector<int> listB;
	if (A.fill_list(listB, argv + 1) != 0)
		return (3);
	std::cout << "Before:\t";
	A.print_list(listB);

	A.mergeSort(listB);

	std::cout << "After:\t";
	A.print_list(listB);

	return (0);
}