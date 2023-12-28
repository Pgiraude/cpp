#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void)
{
    //std::cout << "PmergeMe VOID " << GREEN "constructor" RESET << " called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy) : _sortVector(copy._sortVector), _sortList(copy._sortList)
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
	_sortList = rhs._sortList;
	_sortVector = rhs._sortVector;
    //std::cout << "PmergeMe '=' " << YELLOW "assignement" RESET << " called" << std::endl;
    return (*this);
}

std::vector<int>	&PmergeMe::getVector(void)
{
	return (this->_sortVector);
}

std::list<int>	&PmergeMe::getList(void)
{
	return (this->_sortList);
}

//--------------------------- MergeSort + Tester --------------------------------

int PmergeMe::check_input(int argc, char **argv)
{
	if (argc < 2)
		throw PmergeMe::NotEnoughArguments();
	for (int idx = 1; idx < argc; idx++)
		for (int i = 0; argv[idx][i]; i++)
			if (!isdigit(argv[idx][i]) && !isblank(argv[idx][i]))
				throw PmergeMe::InvalidInput();
	return (0);
}

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

void	PmergeMe::tester(int argc, char **argv)
{
	std::vector<int> container;
	try
	{
		check_input(argc, argv);
		fill_container(container, argv + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	mergeSort(container);
	std::vector<int>::iterator it = container.begin();
	std::list<int>::iterator it2 = _sortList.begin();
	std::vector<int>::iterator it3 = _sortVector.begin();
	while (it != container.end())
	{
		if (*it != *it2)
		{
			std::cout << RED "KO: LIST" RESET << std::endl;
			return ;
		}
		if (*it != *it3)
		{
			std::cout << RED "KO: VECTOR" RESET << std::endl;
			return ;
		}
		it++;
		it2++;
		it3++;
	}
	std::cout << GREEN "OK" RESET << std::endl;
}

// ------------------ jackobsthal numbers -------------

std::size_t	PmergeMe::getJacobsthalNum(std::size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (getJacobsthalNum(n - 1) + 2 * getJacobsthalNum(n - 2));
}

// VECTOR ---------------------- 1st steps Ford-johnson algorithm Split Pairs Vector ----------------------

std::vector< std::pair<int, int> > splitInPairs(std::vector<int> &Array)
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

void sortIndividualPairs(std::vector< std::pair<int, int> > &pairVector)
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

void	sortPairsByLargerValue(std::vector< std::pair<int, int> > &pairVector, std::size_t size)
{
	if (size < 1)
		return ;
	sortPairsByLargerValue(pairVector, size - 1);
	int					j = size - 2;
	std::pair<int, int>	lastPair = pairVector[size - 1];
	while (j >= 0 && pairVector[j].second > lastPair.second)
	{
		pairVector[j + 1] = pairVector[j];
		j--;
	}
	pairVector[j + 1] = lastPair;
}

// VECTOR ---------------------- 2nd steps Ford-johnson algorithm Sort Vector ----------------------

std::vector<int>	PmergeMe::splitPairContainer(std::vector< std::pair<int, int> > &pairVector)
{
	std::vector<int> pending;
	for (std::vector< std::pair<int, int> >::iterator it = pairVector.begin();
		it != pairVector.end(); it++)
	{
		pending.push_back(it->first);
		this->_sortVector.push_back(it->second);
	}
	if (this->_isTale == true)
		pending.push_back(this->_tale);
	return (pending);
}

void	PmergeMe::finalInsertionVector(int value)
{
	std::vector<int>::iterator it = this->_sortVector.begin();
	while (*it < value && it != this->_sortVector.end())
		it++;
	this->_sortVector.insert(it, value);
}

void	PmergeMe::jackobsthalInsertionVector(std::vector<int> &pending)
{
	std::size_t					sizePending = pending.size();
	std::vector<int>::iterator	begin = pending.begin();
	std::vector<int>::iterator	save;

	this->_sortVector.insert(this->_sortVector.begin(), *begin);
	std::size_t	position = 0;
	std::size_t	cycle = 1;
	while (position + 1 < sizePending)
	{
		save = begin + position;
		position += getJacobsthalNum(cycle) * 2;
		if (position >= sizePending)
			position = sizePending - 1;
		for (std::vector<int>::iterator it = (begin + position); it != save; it--)
			finalInsertionVector(*it);
		cycle++;
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
	std::vector< std::pair<int, int> > pairVector = splitInPairs(Array);
	sortIndividualPairs(pairVector);
	sortPairsByLargerValue(pairVector, pairVector.size());
	std::vector<int> pending = splitPairContainer(pairVector);
	jackobsthalInsertionVector(pending);
}

// LIST ---------------------- 1st steps Ford-johnson algorithm Split Pairs List ----------------------

std::list< std::pair<int, int> > splitInPairs(std::list<int> &Array)
{
	std::list< std::pair<int, int> > pair;
	int lastValue;
	std::list<int>::iterator it = Array.begin();
	for (std::size_t i = 0; i != Array.size(); i++)
	{
		if (i % 2 == 0)
			lastValue = *it;
		else
			pair.push_back(std::make_pair(lastValue, *it));
		it++;
	}
	return (pair);
}

void sortIndividualPairs(std::list< std::pair<int, int> > &pair)
{
	std::list< std::pair<int, int> >::iterator it = pair.begin();
	while (it != pair.end())
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

void	sortPairsByLargerValue(std::list< std::pair<int, int> > &pairList, std::size_t size)
{
	if (size < 1)
		return ;
	std::pair<int, int>	lastPair = pairList.back();
	pairList.pop_back();
	sortPairsByLargerValue(pairList, size - 1);
	std::list< std::pair<int, int> >::iterator it = pairList.begin();
	while (it != pairList.end() && it->second < lastPair.second)
		it++;
	pairList.insert(it, lastPair);
}

// LIST ---------------------- 2nd steps Ford-johnson algorithm Sort List ----------------------

std::list<int>	PmergeMe::splitPairContainer(std::list< std::pair<int, int> > &pair)
{
	std::list<int> pending;
	for (std::list< std::pair<int, int> >::iterator it = pair.begin();
		it != pair.end(); it++)
	{
		pending.push_back(it->first);
		this->_sortList.push_back(it->second);
	}
	if (this->_isTale == true)
		pending.push_back(this->_tale);
	return (pending);
}

void	PmergeMe::finalInsertionList(int value)
{
	std::list<int>::iterator it = this->_sortList.begin();
	while (*it < value && it != this->_sortList.end())
		it++;
	this->_sortList.insert(it, value);
}

void	PmergeMe::jackobsthalInsertionList(std::list<int> &pending)
{
	std::size_t					sizePending = pending.size();
	std::list<int>::iterator	index = pending.begin();
	std::list<int>::iterator	save;

	this->_sortList.insert(this->_sortList.begin(), *index);
	std::size_t	next_jump = 0;
	std::size_t pos = 1;
	std::size_t	cycle = 1;
	while (pos < sizePending)
	{
		save = index;
		next_jump = getJacobsthalNum(cycle) * 2;
		for (std::size_t i = pos; i < sizePending && i < pos + next_jump; i++)
			index++;
		for (std::list<int>::iterator it = index; it != save; it--)
			finalInsertionList(*it);
		pos += next_jump;
		cycle++;
	}
}

void PmergeMe::mergeInsertionSort(std::list<int> &Array)
{
	if (Array.size() == 1)
	{
		_sortList.push_back(Array.front());
		return ;
	}
	checkIfOddSize(Array);
	std::list< std::pair<int, int> > pairList = splitInPairs(Array);
	sortIndividualPairs(pairList);
	sortPairsByLargerValue(pairList, pairList.size());
	std::list<int> pending = splitPairContainer(pairList);
	jackobsthalInsertionList(pending);
}