#include "ScalarConverter.hpp"

float inf = std::numeric_limits<float>::infinity();
double inff = std::numeric_limits<double>::infinity();


int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    
    ScalarConverter A;
    A.printchar(argv[1]);
    A.printint(argv[1]);
    A.printfloat(argv[1]);
    A.printdouble(argv[1]);

    // double F = 10;
    std::cout << -1 * inf << inff << std::endl;
}

