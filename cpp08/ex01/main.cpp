#include "Span.hpp"

int	main(void)
{
	Span	sp;
	Span	sp2;

	try
	{
		sp = Span(10000);
		std::vector<int> numbers;
		for (int i = 0; i < 10000; i++)
		{
			numbers.push_back(i);
		}
		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	sp2 = Span(5);
	sp2.addNumber(6);
	sp2.addNumber(3);
	sp2.addNumber(17);
	sp2.addNumber(9);
	sp2.addNumber(11);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return (0);
}
