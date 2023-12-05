#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void)
{
    //std::cout << "PmergeMe VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
    (void)copy;
    //std::cout << "PmergeMe COPY " << GREEN "constructor" RESET << " called" << std::endl;
}

PmergeMe::~PmergeMe(void)
{
    //std::cout << "PmergeMe VOID " << RED "destructor" RESET << " called" << std::endl;
}

PmergeMe    &PmergeMe::operator=(PmergeMe const &rhs)
{
    (void)rhs;
    //std::cout << "PmergeMe '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

//MergeSort vector

void static merge(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &finalArray)
{
	std::size_t leftSize = finalArray.size() / 2;
	std::size_t rightSize = finalArray.size() - leftSize;
	std::size_t idx = 0, l = 0, r = 0;
	while (l < leftSize && r < rightSize)
	{
		if (leftArray[l] < rightArray[r])
			finalArray[idx++] = leftArray[l++];
		else
			finalArray[idx++] = rightArray[r++];
	}
	while (l < leftSize)
		finalArray[idx++] = leftArray[l++];
	while(r < rightSize)
		finalArray[idx++] = rightArray[r++];
}

void PmergeMe::mergeSort(std::vector<int> &Array)
{
	if (Array.size() <= 1)
		return ;
	std::size_t middle = Array.size() / 2;
	std::vector<int> leftArray;
	std::vector<int> rightArray;
	leftArray.insert(leftArray.begin(), Array.begin(), Array.begin() + middle);
	rightArray.insert(rightArray.begin(), Array.begin() + middle, Array.end());

	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, Array);
}

//MergeSort list

void static merge(std::list<int> &leftArray, std::list<int> &rightArray, std::list<int> &finalArray)
{
	std::size_t leftSize = finalArray.size() / 2;
	std::size_t rightSize = finalArray.size() - leftSize;
	std::size_t idx = 0, l = 0, r = 0;
	while (l < leftSize && r < rightSize)
	{
		if (leftArray[l] < rightArray[r])
			finalArray[idx++] = leftArray[l++];
		else
			finalArray[idx++] = rightArray[r++];
	}
	while (l < leftSize)
		finalArray[idx++] = leftArray[l++];
	while(r < rightSize)
		finalArray[idx++] = rightArray[r++];
}

void PmergeMe::mergeSort(std::list<int> &Array)
{
	if (Array.size() <= 1)
		return ;
	std::size_t middle = Array.size() / 2;
	std::list<int> leftArray;
	std::list<int> rightArray;
    std::list<int>::iterator it = Array.begin();
    std::size_t i = 0;
    while (i < middle)
    {
        it++;
        i++;
    }
	leftArray.insert(leftArray.begin(), Array.begin(), it);
	rightArray.insert(rightArray.begin(), it, Array.end());

	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, Array);
}