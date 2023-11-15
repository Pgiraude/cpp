#include "Span.hpp"

int main(void)
{
	std::cout << "-------Test n1 basique test-----------" << std::endl;
	{
		Span toto(8);

		try{
			toto.addNumber(10);
			toto.addNumber(800);
			toto.addNumber(1);
			toto.addNumber(3);
			std::cout << "longestSpan = " << toto.longestSpan() << std::endl;
			std::cout << "shortestSpan = " << toto.shortestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		std::cout << toto;
	}
	std::cout <<  "\n-------Test n2 lots of random value-----------" << std::endl;
	{
		Span toto(20000);

		try{
			toto.fillArray();
			std::cout << "longestSpan = " << toto.longestSpan() << std::endl;
			std::cout << "shortestSpan = " << toto.shortestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout <<  "\n-------Test n3 subject main-----------" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout <<  "\n-------Test n4 array size = 0-----------" << std::endl;
	{
		Span toto(0);
		try{
			std::cout << "addNumber(10) ";
		toto.addNumber(10);
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		try{
		std::cout << "shortestSpan = " << toto.shortestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		try{
		std::cout << "longestSpan = " << toto.longestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		std::cout << toto;
	}
	std::cout <<  "\n-------Test n5 arraySize = 1 -> array full and too small-----------" << std::endl;
	{
		Span toto(1);
		try{
		std::cout << "AddNumber ";
		toto.addNumber(10);
		toto.addNumber(15);
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		try{
		std::cout << "shortestSpan = " << toto.shortestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		try{
		std::cout << "longestSpan = " << toto.longestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		Span test(1);
		test.fillArray();
		std::vector<int>::const_iterator begin = test.getArray().begin();
		std::vector<int>::const_iterator end = test.getArray().end();
		try{
		toto.addNumber(begin, end);
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		std::cout << toto;
	}
	std::cout <<  "\n-------Test n6 copy-----------" << std::endl;
	{
		Span toto(5);
		toto.fillArray();
		Span copy1(toto);
		Span copy2(18);
		copy2.fillArray();
		copy2 = toto;
		Span copy3(5);
		std::vector<int>::const_iterator begin = toto.getArray().begin();
		std::vector<int>::const_iterator end = toto.getArray().end();
		copy3.addNumber(begin, end);

		std::cout << GREEN "original " RESET << toto;
		std::cout << YELLOW "copy1 " RESET << copy1;
		std::cout << YELLOW "copy2 " RESET << copy2;
		std::cout << YELLOW "copy3 " RESET << copy3;
	}
	std::cout <<  "\n-------Test n7 add multiple Numbers-----------" << std::endl;

	{
		Span toto(8);

		Span test(1);
		test.addNumber(88);
		std::vector<int>::const_iterator begin = test.getArray().begin();
		std::vector<int>::const_iterator end = test.getArray().end();

		Span test2(2);
		test2.fillArray();
		std::vector<int>::const_iterator begin2 = test2.getArray().begin();
		std::vector<int>::const_iterator end2 = test2.getArray().end();

		try{
			toto.addNumber(10);
			toto.addNumber(11);
			toto.addNumber(begin, end);
			toto.addNumber(begin2, end2);
			std::cout << "longestSpan = " << toto.longestSpan() << std::endl;
			std::cout << "shortestSpan = " << toto.shortestSpan() << std::endl;
		}
		catch(std::exception &e){
			std::cerr << e.what() << '\n';
		}
		std::cout << "result should be : 10, 11, 88, [random], [random]" << std::endl;
		std::cout << toto;
	}
}