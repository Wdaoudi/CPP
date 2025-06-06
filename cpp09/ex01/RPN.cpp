#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string &string)
{
	fileStack(string);
}

RPN::RPN(const RPN &other)
	: _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::fileStack(const std::string &string)
{
	int	number;
	int	i;

	i = 0;
	(void)number;
	(void)string;
	while (string[i])
	{
		if (string[i] == ' ' || string[i] == '\t')
			i++;
		if (string[i] >= '0' && string[i] <= '9')
		{
			_stack.push((string[i]) - '0');
			if (!(string[i + 1] == ' ' || string[i + 1] == '\0' || string[i
					+ 1] == '\t'))
			{
				std::cerr << "Error: missing a whitespace" << std::endl;
				return ;
			}
			i++;
		}
		if (string[i] == '+' || string[i] == '/' || string[i] == '*'
			|| string[i] == '-')
		{
			if (!(string[i + 1] == ' ' || string[i + 1] == '\0' || string[i
					+ 1] == '\t'))
			{
				std::cerr << "Error: missing a whitespace" << std::endl;
				return ;
			}
			if (handle_operator(string[i]) == false)
				return ;
			i++;
		}
		if (string[i] == '(' || string[i] == ')' || string[i] == '.'
			|| string[i] == 'f')
		{
			std::cerr << "Error: invalid char or missing operator" << std::endl;
			return ;
		}
	}
	if (_stack.size() > 1)
	{
		std::cerr << "Error: missing operator" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
	return ;
}

bool RPN::handle_operator(char i)
{
	if (_stack.size() < 2)
	{
		std::cerr << "Error: not enough number in the stack" << std::endl;
		return (false);
	}
	int a;
	int b;
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	long long result;

	switch (i)
	{
	case '+':
		// std::cout << "a+b=" << a << "+" << b << " = "<< a+b << std::endl;
		result = static_cast<long long>(a) + static_cast<long long>(b);
		if (result > INT_MAX || result < INT_MIN)
		{
			std::cerr << "Error : Int overflow" << std::endl;
			return (false);
		}
		_stack.push(static_cast<int>(result));
		break ;
	case '-':
		// std::cout << "a-b=" << a << "-" << b << " = "<< a-b << std::endl;
		result = static_cast<long long>(a) - static_cast<long long>(b);
		if (result > INT_MAX || result < INT_MIN)
		{
			std::cerr << "Error : Int overflow" << std::endl;
			return (false);
		}
		_stack.push(static_cast<int>(result));
		break ;
	case '*':
		// std::cout << "a*b=" << a << "*" << b << " = "<< a*b << std::endl;
		result = static_cast<long long>(a) * static_cast<long long>(b);
		if (result > INT_MAX || result < INT_MIN)
		{
			std::cerr << "Error : Int overflow" << std::endl;
			return (false);
		}
		_stack.push(static_cast<int>(result));
		break ;
	case '/':
		// std::cout << "a/b=" << a << "/" << b << " = "<< a/b << std::endl;
		if (b == 0)
		{
			std::cerr << "Error: division by 0 can t be" << std::endl;
			return (false);
		}
		result = static_cast<long long>(a) / static_cast<long long>(b);
		if (result > INT_MAX || result < INT_MIN)
		{
			std::cerr << "Error : Int overflow" << std::endl;
			return (false);
		}
		_stack.push(static_cast<int>(result));
		break ;
	}
	return (true);
}