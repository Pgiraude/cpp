#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

# define RESET	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

Base *generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    switch(random)
    {
        case 0:
            std::cout << "Real type is: A";
            return (new A);
        case 1:
            std::cout << "Real type is: B";
            return (new B);
        case 2:
            std::cout << "Real type is: C";
            return (new C);
    }
    return (NULL);
}

void identify(Base *p)
{
    std::cout << CYAN "By pointer - " RESET;
    A   *a = dynamic_cast<A *>(p);
    if (a != NULL)
    {
        std::cout << CYAN "type identify is: A" RESET;
        return ;
    }
    B   *b = dynamic_cast<B *>(p);
    if (b != NULL)
    {
        std::cout << CYAN "type identify is: B" RESET;
        return ;
    }
    C   *c = dynamic_cast<C *>(p);
    if (c != NULL)
    {
        std::cout << CYAN "type identify is: C" RESET;
        return ;
    }
    std::cout << CYAN "type identify is: Unknown" RESET;
}

void identify(Base &p)
{
    std::cout << PURPLE "By reference - " RESET;
    try{
    A   &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << PURPLE "type identify is: A" RESET;
    }
    catch(std::exception &e) {};
    try{
    B   &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << PURPLE "type identify is: B" RESET;
    }
    catch(std::exception &e) {};
    try{
    C   &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << PURPLE "type identify is: C" RESET;
    }
    catch(std::exception &e) {};
}

int main(void)
{
    Base *base = generate();
    std::cout << "\t";
    identify(base);
    std::cout << "\t";
    identify(*base);
    std::cout << std::endl;
    delete base;
}