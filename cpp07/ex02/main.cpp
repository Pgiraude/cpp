#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    Array<int> numbers(10);
    
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 1440;
    }
    numbers[9] = 100;
    std::cout << numbers<< std::endl;

    Array<int> nbr(5);
    nbr = numbers;

    std::cout << nbr;

}