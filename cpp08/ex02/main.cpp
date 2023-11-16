#include "MutantStack.hpp"

int main(void)
{
	std::cout << "\n----------Test n1 subject---------\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "stack.Top() = 17  result : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "stack.Size() = 1  result : " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << "[" << *it << "] ";
		++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	std::cout << "\n----------Test n2 assign other container---------\n";
	{
		std::stack<float, std::vector<std::string> > origin;
		origin.push("first element");
		origin.push("fffffggdggf");
		origin.push("last element");

		MutantStack<float, std::vector<std::string> > stack;
		stack.push("first element");
		stack.push("ffdgdphdphgfo");
		stack.push("last element");
		std::cout << "Stack.top()        = " << origin.top() << std::endl;
		std::cout << "MutantStack.top()  = " << stack.top() << std::endl;
		std::cout << "Stack.size()       = " << origin.size() << std::endl;
		std::cout << "MutantStack.size() = " << stack.size() << std::endl;
	}
	std::cout << "\n----------Test n3 const_iterator and copy container---------\n";
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(15);
		mstack.push(-3);
		mstack.push(-100);
		mstack.pop();

		std::deque<int> deque;
		deque.push_back(5);
		deque.push_back(17);
		deque.push_back(15);
		deque.push_back(-3);
		deque.push_back(-100);
		deque.pop_back();

		MutantStack<int> copystack(mstack);

		MutantStack<int> copystack2 = mstack;

		std::cout << "deque Container      : ";
		for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		
		std::cout << "Original Mutantstack : ";
		for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		std::cout << "Copy Mutantstack     : ";
		for (MutantStack<int>::const_iterator it = copystack.begin(); it != copystack.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		std::cout << "Copy '=' Mutantstack : ";
		for (MutantStack<int>::const_iterator it = copystack2.begin(); it != copystack2.end(); ++it)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
	}

	
}