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

//---------------------------MergeSort vector --------------------------------

void static merge(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &finalArray)
{
	std::size_t idx = 0, l = 0, r = 0;
	while (l < leftArray.size() && r < rightArray.size())
	{
		if (leftArray[l] < rightArray[r])
			finalArray[idx++] = leftArray[l++];
		else
			finalArray[idx++] = rightArray[r++];
	}
	while (l < leftArray.size())
		finalArray[idx++] = leftArray[l++];
	while(r < rightArray.size())
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

//---------------MergeSort list------------------------

void static merge(std::list<int> &leftArray, std::list<int> &rightArray, std::list<int> &sortArray)
{
	std::list<int>::iterator idx = sortArray.begin(), l = leftArray.begin(), r = rightArray.begin();
	while (l != leftArray.end() && r != rightArray.end())
	{
		if (*l < *r)
			*idx++ = *l++;
		else
			*idx++ = *r++;
	}
	while (l != leftArray.end())
		*idx++ = *l++;
	while(r != rightArray.end())
		*idx++ = *r++;
}

void PmergeMe::mergeSort(std::list<int> &Array)
{
	if (Array.size() <= 1)
		return ;
	std::list<int> leftArray;
	std::list<int> rightArray;
    std::list<int>::iterator it_middle = Array.begin();
    for (std::size_t i = 0; i < Array.size() / 2; i++)
		it_middle++;
	leftArray.insert(leftArray.begin(), Array.begin(), it_middle);
	rightArray.insert(rightArray.begin(), it_middle, Array.end());
	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, Array);
}

// ---------------------- Ford-johnson algorithm ----------------------

std::vector< std::pair<int, int> > pairSplit(std::vector<int> &Array)
{
	std::vector< std::pair<int, int> > pairVector;
	int lastValue;
	std::vector<int>::iterator it = Array.begin();
	for (std::size_t i = 0; i != Array.size(); i++)
	{
		if (i % 2 == 0)
			lastValue = *it;
		else
			pairVector.push_back(std::make_pair(lastValue, *it));
		it++;
	}
	return (pairVector);
}

void sortPairs(std::vector< std::pair<int, int> > &pairVector)
{
	std::vector< std::pair<int, int> >::iterator it = pairVector.begin();
	while (it != pairVector.end())
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		it++;
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int> &Array)
{
	std::vector< std::pair<int, int> > pairVector = pairSplit(Array);
	sortPairs(pairVector);
	for (std::vector< std::pair<int, int> >::iterator it =  pairVector.begin(); it != pairVector.end(); it++) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
    std::cout << std::endl;


}