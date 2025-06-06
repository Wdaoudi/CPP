#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Not the good amount of argument" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);    
    return (0);
}
/*
gerer les overflow, 
verifier les precisions 
*/