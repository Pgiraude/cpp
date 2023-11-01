#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    
    ScalarConverter A;
    A.printchar(argv[1]);
    A.printint(argv[1]);
    A.printfloat(argv[1]);
    A.printdouble(argv[1]);

    double F = 15444646640.98;
    std::cout << F << std::endl;
}

