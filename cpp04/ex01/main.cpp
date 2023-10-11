
#include "Cat.hpp"
#include "Dog.hpp"


int main(void)
{
	std::cout << "-----------test n1 Animal------------" <<std::endl;
	{
		const Animal *dog = new Dog;

		std::cout << *dog;
		delete dog;
	}
	std::cout << std::endl << "-----------test n2 array------------" <<std::endl;
	{
		Animal *tab[10];

		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				tab[i] = new Dog;
			else
				tab[i] = new Cat;
			std::cout << "-----------" << std::endl;
		}
		std::cout << "------Destructor-----" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete tab[i];
			std::cout << "-----------" << std::endl;
		}
	}
	std::cout << std::endl << "-----------test n3 copy profond------------" <<std::endl;
	{
		Cat pif;
		std::cout << "-----------" << std::endl;
		pif.setIdeas("OK", 0);
		std::cout << "pif ideas = " << pif.getIdeas(0) << std::endl;
		std::cout << "-----------" << std::endl;
		Cat paf;
		paf = pif;
		std::cout << "paf ideas = " << paf.getIdeas(0) << std::endl;
		std::cout << "-----------" << std::endl;
		paf.setIdeas("NOT OK", 0);
		std::cout << "pif ideas = " << pif.getIdeas(0) << std::endl;
		std::cout << "paf ideas = " << paf.getIdeas(0) << std::endl;
		std::cout << "------destructor-----" << std::endl;

	}
	std::cout << std::endl << "-----------test n4 copy------------" <<std::endl;
	{
		Dog pif;
		std::cout << "-----------" << std::endl;
		pif.setIdeas("OK", 0);
		std::cout << "pif ideas = " << pif.getIdeas(0) << std::endl;
		std::cout << "-----------" << std::endl;
		Dog paf(pif);

		std::cout << "paf ideas = " << paf.getIdeas(0) << std::endl;
		std::cout << "-----------" << std::endl;
		paf.setIdeas("NOT OK", 0);
		std::cout << "pif ideas = " << pif.getIdeas(0) << std::endl;
		std::cout << "paf ideas = " << paf.getIdeas(0) << std::endl;
		std::cout << "------destructor-----" << std::endl;
		
	}
	std::cout << std::endl << "-----------test n5 test deep copy------------" <<std::endl;
	{
		Cat A;
		Cat B;

		A.setIdeas("lol", 1);
		std::cout << "CAT A ideas = " << A.getIdeas(1) << std::endl << std::endl;
		B = A;
		std::cout << "CAT B ideas = " << B.getIdeas(1) << std::endl << std::endl;
		A.setIdeas("NON", 1);
		std::cout << "CAT A ideas = " << A.getIdeas(1) << std::endl;
		std::cout << "CAT B ideas = " << B.getIdeas(1) << std::endl << std::endl;
	}
	std::cout << std::endl << "-----------test n6 Brain copy------------" <<std::endl;
	{
		Brain A;
		Brain B;

		A.setIdeas("lol", 1);
		std::cout << "BRAIN A ideas = " << A.getIdeas(1) << std::endl << std::endl;
		B = A;
		std::cout << "BRAIN B ideas = " << B.getIdeas(1) << std::endl << std::endl;
		A.setIdeas("NON", 1);
		std::cout << "BRAIN A ideas = " << A.getIdeas(1) << std::endl;
		std::cout << "BRAIN B ideas = " << B.getIdeas(1) << std::endl << std::endl;
	}
}