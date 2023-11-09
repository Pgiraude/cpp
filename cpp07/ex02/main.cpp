#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "----------TEST MAIN INTRA---------" << std::endl << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Try acces wrong array pos [-2] -> " << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Try acces wrong array pos [Max_VAL] -> " << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}

	std::cout << "----------MY TEST---------" << std::endl << std::endl;
	{
		Array<int> numbers(5);

		for (int i = 0; i < 5; i++)
		{
			numbers[i] = 1440;
		}
		numbers[4] = 100;
		std::cout << numbers<< std::endl;

		Array<int> nbr(18);
		nbr = numbers;

		std::cout << nbr;
	}

}