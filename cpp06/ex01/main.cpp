#include "Serialization.hpp"

int main(void)
{
    Data A = { .age = 28, .name = "Paul", .sport = "Tennis"};

    std::cout << "A - age:\t" << A.age << "\tadress age:\t" << &(A.age) << std::endl;
    std::cout << "A - sport:\t" << A.sport << "\tadress sport:\t" << &(A.sport) << std::endl;
    std::cout << "A - name:\t" << A.name << "\tadress name:\t" << &(A.name) << std::endl << std::endl;

    uintptr_t   raw = Serialization::serialize(&A);
    std::cout << "Data A reinterpret value after serialisation:\t" << raw << std::endl << std::endl;
    
    Data *B = Serialization::deserialize(raw);
    std::cout << "B - age:\t" << B->age << "\tadress age:\t" << &(B->age) << std::endl;
    std::cout << "B - sport:\t" << B->sport << "\tadress sport:\t" << &(B->sport) << std::endl;
    std::cout << "B - name:\t" << B->name << "\tadress name:\t" << &(B->name) << std::endl << std::endl;

}