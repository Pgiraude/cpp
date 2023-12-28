#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe			algo;
	std::list<int>		containerA;
	std::vector<int>	containerB;

	try{
		algo.check_input(argc, argv);
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
	clock_gettime(CLOCK_REALTIME, &start);
	algo.mergeInsertionSort(containerA);
	clock_gettime(CLOCK_REALTIME, &end);
	double listTime = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec)) / 1000;
	std::cout << "After:\t";
	algo.print_container(algo.getVector());
	std::cout << "Time to process a range of " << algo.getList().size() << " elements with std::list   : " << listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << algo.getVector().size() << " elements with std::vector : " << vectorTime << " us" << std::endl;

	// algo.tester(argc, argv);
	return (0);
}