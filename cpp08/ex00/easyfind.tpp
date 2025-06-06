template <typename T>
typename T::iterator easyfind(T &contenair, int value)
{
	typename T::iterator it = std::find(contenair.begin(), contenair.end(),
			value);
	if (it == contenair.end())
		throw std::out_of_range("Element not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Element not found");
    return (it);
}

//for the test
template <typename T>
void testEasyfind(const T &container, int value, const std::string &name)
{
    std::cout << "Test " << name << " [" << value << "]: ";
    try
    {
        typename T::const_iterator result = easyfind(container, value);
        std::cout << "Found at position " << std::distance(container.begin(), result) + 1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Not found - " << e.what() << std::endl;
    }
}