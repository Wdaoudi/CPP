/*
stack
*/

#include "RPN.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)**av;

    if (ac != 2)
    {
        std::cerr << "Error: not enough argument" << std::endl;
        return 1;
    }

    // const std::string string = " 8  9 * 9 - 9 - 9 - 4 - 1 +      ";
    RPN rpn(av[1]);    
    return 0;
}

/*
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
*/