#include "Span.hpp"

int main(void)
{
	Span toto(4);

		// toto.addNumber(10);
		// toto.addNumber(800);

	try{
	toto.fillArray();
		// toto.addNumber(5);
	}
	catch(std::exception &e){
		std::cerr << e.what() << '\n';
	}
	// std::cout << toto.getArray().size() << std::endl;
	std::cout << toto;
}