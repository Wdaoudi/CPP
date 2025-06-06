#include "iter.hpp"

template <typename T>
void	print(T const &c)
{
	std::cout << c << std::endl;
}
template <typename T>
void	increment(T &a)
{
	std::cout <<"before : " << a << std::endl;
	a +=1;
	std::cout << "after : " << a << std::endl;
}

template <typename T>
void display(T const &a)
{
    std::cout << "value : " << a << std::endl;
}

int	main(void)
{
	// Test with integer array
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = 5;

	std::cout << "Testing with integer array:" << std::endl;
	std::cout << "Printing integers:" << std::endl;
	iter(intArray, intArrayLength, print<int>);

	std::cout << "\nDisplaying integers:" << std::endl;
	iter(intArray, intArrayLength, display<int>);

	std::cout << "\nIncrementing integers:" << std::endl;
	iter(intArray, intArrayLength, increment<int>);

	std::cout << "\nPrinting after increment:" << std::endl;
	iter(intArray, intArrayLength, print<int>);

	// Test with floating point array
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = 5;

	std::cout << "\nTesting with double array:" << std::endl;
	std::cout << "Printing doubles:" << std::endl;
	iter(doubleArray, doubleArrayLength, print<double>);

	// Test with string array
	std::string stringArray[] = {"Hello", "World", "Templates", "Test",
		"Fine"};
	size_t stringArrayLength = 5;

	std::cout << "\nTesting with string array:" << std::endl;
	std::cout << "Printing strings:" << std::endl;
	iter(stringArray, stringArrayLength, print<std::string>);

	std::cout << "\nDisplaying strings:" << std::endl;
	iter(stringArray, stringArrayLength, display<std::string>);

	return (0);
}