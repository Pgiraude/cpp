#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED "Error:" RESET " need one argument" << std::endl;
        return (1);
    }

    RPN algo;
    try{
    algo.processing(argv[1]);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}