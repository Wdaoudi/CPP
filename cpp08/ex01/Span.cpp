#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		tab = other.tab;
	}
	return (*this);
}

Span::Span(const Span &other)
{
	_N = other._N;
	tab = other.tab;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (tab.size() >= _N)
		throw NotEnoughPlace();
	tab.push_back(number); // push back optimised for adding single number
}

unsigned int Span::shortestSpan()
{
	unsigned int	minSpan;
	unsigned int	currentSpan;

	if (tab.size() < 2)
		throw NoSpan();
	std::vector<int> tab2 = tab;
	std::sort(tab2.begin(), tab2.end());
	minSpan = UINT_MAX;
	for (std::vector<int>::iterator it = tab2.begin(); it != tab2.end()
		- 1; ++it)
	{
		currentSpan = static_cast<unsigned int>(*(it + 1) - *it);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return (minSpan);
}
unsigned int Span::longestSpan()
{
	if (tab.size() < 2)
		throw NoSpan();
	std::vector<int>::iterator min = std::min_element(tab.begin(), tab.end());
	std::vector<int>::iterator max = std::max_element(tab.begin(), tab.end());
	return (static_cast<unsigned int>(*max - *min));
}