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
	std::vector<int>	containerB;

	try{
		check_input(argc, argv);
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
	algo.print_container(containerA);

	clock_gettime(CLOCK_REALTIME, &start);
	algo.mergeSort(containerA);
	clock_gettime(CLOCK_REALTIME, &end);
	double listTime = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000;

	std::cout << "After:\t";
	algo.print_container(containerA);

	clock_gettime(CLOCK_REALTIME, &start);
	algo.mergeSort(containerB);
	clock_gettime(CLOCK_REALTIME, &end);
	double vectorTime = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000;

	std::cout << "Time to process a range of " << containerA.size() << " elements with std::list   : " << listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << containerB.size() << " elements with std::vector : " << vectorTime << " us" << std::endl;

	return (0);
}