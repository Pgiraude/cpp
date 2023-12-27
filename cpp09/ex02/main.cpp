#include "PmergeMe.hpp"

int check_input(int argc, char **argv)
{
	if (argc < 2)
		throw PmergeMe::NotEnoughArguments();
	for (int idx = 1; idx < argc; idx++)
		for (int i = 0; argv[idx][i]; i++)
			if (!isdigit(argv[idx][i]) && !isblank(argv[idx][i]))
				throw PmergeMe::InvalidInput();
	return (0);
}

int main(int argc, char **argv)
{
	PmergeMe			algo;
	std::list<int>		containerA;
	std::list<int>		containerC;
	std::vector<int>	containerB;

	try{
		check_input(argc, argv);
		algo.fill_container(containerC, argv + 1);
		algo.fill_container(containerA, argv + 1);
		algo.fill_container(containerB, argv + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	struct timespec start, end;

	std::cout << "Before:\t";
	algo.print_container(containerB);

	clock_gettime(CLOCK_REALTIME, &start);

	algo.mergeInsertionSort(containerB);

	clock_gettime(CLOCK_REALTIME, &end);
	double vectorTime = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000;

	std::cout << "After:\t";
	algo.print_container(algo.getVector());

	std::cout << "-----------LIST-----------\n";

	algo.print_container(algo.getList());

	clock_gettime(CLOCK_REALTIME, &start);
	algo.mergeInsertionSort(containerA);
	clock_gettime(CLOCK_REALTIME, &end);
	double listTime = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000;

	algo.print_container(algo.getList());

	std::cout << "Time to process a range of " << containerA.size() << " elements with std::list   : " << listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << containerB.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;


	algo.mergeSort(containerC);
	std::cout << "C :";
	algo.print_container(containerC);
	std::list<int>::iterator it = containerC.begin();
	std::list<int>::iterator it2 = algo.getList().begin();
	std::vector<int>::iterator it3 = algo.getVector().begin();

	while (it != containerC.end())
	{
		if (*it != *it2)
			std::cout << "KKOO LIST" << std::endl;
		if (*it != *it3)
			std::cout << "KKOO VECTOR" << std::endl;
		it++;
		it2++;
		it3++;
	}
	return (0);
}