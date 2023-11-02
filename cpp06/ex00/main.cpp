#include "ScalarConverter.hpp"

float inf = std::numeric_limits<float>::infinity();
double inff = std::numeric_limits<double>::infinity();


int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    
    ScalarConverter A;
    A.convert(argv[1]);
}

