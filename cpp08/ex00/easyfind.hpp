#pragma once

#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &contenair, int value);

template <typename T>
typename T::const_iterator easyfind(const T &container, int value);


template <typename T>
void testEasyfind(const T& container, int valueToFind, const std::string& containerName);

#include "easyfind.tpp"