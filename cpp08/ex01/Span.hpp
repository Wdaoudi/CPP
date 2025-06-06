#pragma once

#include <algorithm>
#include <climits>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

class Span
{
  private:
	unsigned int _N;
	std::vector<int> tab;

  public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);

	class NotEnoughPlace : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Not enough place in the span !");
		}
	};

	unsigned int shortestSpan();
	unsigned int longestSpan();

	class NoSpan : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("There is no nbr stored or only one !");
		}
	};

	template <typename Iterator> 
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int count = std::distance(begin, end);
	
		if (tab.size() + count > _N)
			throw NotEnoughPlace();
		tab.insert(tab.end(), begin, end);
			//insert optimised for adding range number in any position of the array
		//insert realloc memory and moove the already present numbers
	}
};
