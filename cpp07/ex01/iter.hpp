#pragma once 

#include <iostream>

template <typename T, typename func> // T which could be any type and func any function

void iter(T *array, size_t length, func function)
{
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}