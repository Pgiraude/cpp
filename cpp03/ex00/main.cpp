#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--------test n1 dead bob--------------" << std::endl;
	{
		ClapTrap C1("bob");
	
		std::cout << C1;
		C1.takeDamage(10);
		std::cout << C1;

		std::cout << std::endl << "-> berepaired f(x)" << std::endl;
		C1.beRepaired(5);
		std::cout << C1;

		std::cout << std::endl << "-> takedamage f(x)" << std::endl;
		C1.takeDamage(10);
		std::cout << C1;

		std::cout << std::endl << "-> attack f(x)" << std::endl;
		C1.attack("the neighbor");
		std::cout << C1;
	}
	std::cout << std::endl << "--------test n2 Sam doing stuff--------------" << std::endl;
	{
		ClapTrap C1("Sam");

		std::cout << std::endl << "-> berepaired f(x) but full life" << std::endl;
		C1.beRepaired(5);
		std::cout << C1;

		std::cout << std::endl << "-> attack f(x)" << std::endl;
		C1.attack("the neighbor");
		std::cout << C1;

		std::cout << std::endl << "-> takedamage f(x)" << std::endl;
		C1.takeDamage(9);
		std::cout << C1;

		std::cout << std::endl << "-> berepaired f(x) to full life and more" << std::endl;
		C1.beRepaired(50);
		std::cout << C1;

		std::cout << std::endl << "-> takedamage f(x)" << std::endl;
		C1.takeDamage(9);
		std::cout << C1;

		std::cout << std::endl << "-> berepaired f(x)" << std::endl;
		C1.beRepaired(5);
		std::cout << C1;

		std::cout << std::endl << "-> attack f(x) until exhausted" << std::endl;
		C1.attack("the neighbor");
		C1.attack("the neighbor");
		C1.attack("the neighbor");
		C1.attack("the neighbor dog");
		C1.attack("the neighbor door");
		C1.attack("his own door");
		C1.attack("the police officer");
		std::cout << C1;
		C1.attack("the police officer");
		std::cout << C1;

		std::cout << std::endl << "-> takedamage f(x)" << std::endl;
		C1.takeDamage(5);
		std::cout << C1;

		std::cout << std::endl << "-> berepaired but no energy f(x)" << std::endl;
		C1.beRepaired(5);
		std::cout << C1;
		
		std::cout << std::endl << "-> takedamage kill Sam f(x)" << std::endl;
		C1.takeDamage(5);
		std::cout << C1;

		std::cout << std::endl << "-> berepaired but is dead f(x)" << std::endl;
		C1.beRepaired(5);
		std::cout << C1;

		std::cout << std::endl << "-> attack but is dead f(x)" << std::endl;
		C1.attack("the neighbor");
		std::cout << C1;
	}
	std::cout << std::endl << "--------test n3 copy class--------------" << std::endl;
	{
		ClapTrap C1("bob");

		std::cout << std::endl << "-> Bob takedamage f(x)" << std::endl;
		C1.takeDamage(9);
		std::cout << C1;

		ClapTrap C2;
		std::cout << "default       = " << C2;
		C2 = C1;

		std::cout << "Bob copy	= " << C2;
		std::cout << "Bob		= " << C1;

		std::cout << std::endl << "-> Bob berepaired f(x)" << std::endl;
		C1.beRepaired(5);
		std::cout << "Bob copy	= " << C2;
		std::cout << "Bob		= " << C1;

		std::cout << std::endl << "-> creation of Bob 2nd copy" << std::endl;
		ClapTrap C3(C1);
		std::cout << "Bob 2nd copy  = " << C3;
		std::cout << "Bob           = " << C1;

		std::cout << std::endl << "-> Bob 2nd copy berepaired f(x)" << std::endl;
		C3.beRepaired(5);
		std::cout << "Bob 2nd copy  = " << C3;
		std::cout << "Bob           = " << C1;
	}
	
}