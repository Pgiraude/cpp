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
// ------------------ jackobsthal numbers -------------

long int	getJacobsthalNum(long int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (getJacobsthalNum(n - 1) + 2 * getJacobsthalNum(n - 2));
}

// ---------------------- Ford-johnson algorithm ----------------------

std::vector< std::pair<int, int> > SplitInPairs(std::vector<int> &Array)
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

void SortPairs(std::vector< std::pair<int, int> > &pairVector)
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

void	SortPairsByLargerValue(std::vector< std::pair<int, int> > &pairVector, int size)
{
	if (size < 1)
		return ;
	SortPairsByLargerValue(pairVector, size - 1);
	int					j = size - 2;
	std::pair<int, int>	lastPair = pairVector[size - 1];
	while (j >= 0 && pairVector[j].second > lastPair.second)
	{
		pairVector[j + 1] = pairVector[j];
		j--;
	}
	pairVector[j + 1] = lastPair;
	//InsertionSortPairs(pairVector, size);
}

void	finalInsertion(std::vector<int> &sortvect, int value)
{
	std::vector<int>::iterator it = sortvect.begin();
	while (*it < value && it != sortvect.end())
		it++;
	sortvect.insert(it, value);
}

void	jackobsthalInsertion(std::vector<int> &sortvect, std::vector<int> &pending)
{
	PmergeMe A;

	int sizetot = pending.size();

	std::vector<int>::iterator beg = pending.begin();
	std::vector<int>::iterator save;

	sortvect.insert(sortvect.begin(), *beg);
	A.print_container(sortvect);
	std::cout << "-----------" << std::endl;

	int cycle = 1;
	int position = 0;
	while (position + 1 < sizetot)
	{
		save = beg + position;
		position += getJacobsthalNum(static_cast<long int>(cycle)) * 2;
		if (position >= sizetot)
			position = sizetot - 1;
		for (std::vector<int>::iterator it = (beg + position); it != save; it--)
			finalInsertion(sortvect, *it);
		cycle++;
	}


	A.print_container(sortvect);
	
}

void PmergeMe::checkIfOddSize(std::vector<int> &Array)
{
	this->_isTale = false;
	if (Array.size() % 2 != 0)
	{
		this->_isTale = true;
		this->_tale = Array.back();
		Array.pop_back();
	}
}


void PmergeMe::mergeInsertionSort(std::vector<int> &Array)
{
	if (Array.size() == 1)
	{
		_sortVector.push_back(Array[0]);
		return ;
	}
	checkIfOddSize(Array);

	std::vector< std::pair<int, int> > pairVector = SplitInPairs(Array);
	SortPairs(pairVector);


	for (std::vector< std::pair<int, int> >::iterator it =  pairVector.begin(); it != pairVector.end(); it++) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
		if (this->_isTale == true)
			std::cout << "this->_tale = " << this->_tale;
    std::cout << std::endl;


	SortPairsByLargerValue(pairVector, pairVector.size());


	for (std::vector< std::pair<int, int> >::iterator it =  pairVector.begin(); it != pairVector.end(); it++) {
            std::cout << "(" << it->first << ", " << it->second << ") ";
        }
	if (this->_isTale == true)
		std::cout << "this->_tale = " << this->_tale;
    std::cout << std::endl;

	std::vector<int> sortvect;
	std::vector<int> pending;

	for (std::vector< std::pair<int, int> >::iterator it = pairVector.begin();
		it != pairVector.end(); it++)
	{
		pending.push_back(it->first);
		sortvect.push_back(it->second);
	}
	if (this->_isTale == true)
		pending.push_back(this->_tale);

	std::cout << "sortedvect  = ";
	print_container(sortvect);
	std::cout << "pendingvect = ";
	print_container(pending);

	jackobsthalInsertion(sortvect, pending);

}