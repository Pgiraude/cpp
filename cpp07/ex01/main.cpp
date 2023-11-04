#include "iter.hpp"

void    replace(std::string &str)
{
	for (int i = 0 ; str[i]; i++)
	{
		if (str[i] == ' ')
			str[i] = '*';
	}
}

int	divide(int &value)
{
	value /= 2;
	return (0);
}

int main(void)
{
	std::cout << "------- test n°1 std::string replace ' ' by '*'---------" << std::endl;
	{
		std::string array[4] = {"salut BG", "cool man", "    ", "yahouuuuu"};
		std::cout << CYAN "BEFORE" RESET; 
		for (int i = 0; i < 4; i++)
			std::cout << "\t[" << array[i] << "]";
		std::cout << std::endl;

		iter<std::string, size_t, void>(array, 4, replace);

		std::cout << PURPLE "AFTER" RESET; 
		for (int i = 0; i < 4; i++)
			std::cout << "\t[" << array[i] << "]";
		std::cout << std::endl << std::endl;
	}
	std::cout << "------- test n°2 int divide by 2---------" << std::endl;
	{
		int array[4] = {10, 5555, 40000, -888888};
		std::cout << CYAN "BEFORE" RESET; 
		for (int i = 0; i < 4; i++)
			std::cout << "\t[" << array[i] << "]";
		std::cout << std::endl;

		iter<int, size_t, int>(array, 4, divide);

		std::cout << PURPLE "AFTER" RESET; 
		for (int i = 0; i < 4; i++)
			std::cout << "\t[" << array[i] << "]";
		std::cout << std::endl;
	}
}