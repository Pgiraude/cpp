#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    Array<int> numbers(10);
    
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 10;
    }
    numbers[9] = 100;
    std::cout << "element 0 = " << numbers[0] << std::endl;
    std::cout << "element 9 = " << numbers[9] << std::endl;

}