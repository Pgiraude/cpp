#include "ScalarConverter.hpp"

int main(void)
{
    ScalarConverter A;

    A.printint("c");
    A.printdouble("-15444646640.98");

    double F = 15444646640.98;
    std::cout << F << std::endl;
}

