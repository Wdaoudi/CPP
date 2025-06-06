#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing valid bureaucrats ---" << std::endl;
    try
    {
        Bureaucrat bob(75, "Bob");
        std::cout << bob << std::endl;
        
        Bureaucrat jim(1, "Jim");
        std::cout << jim << std::endl;
        
        Bureaucrat tim(150, "Tim");
        std::cout << tim << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing grade too high exception ---" << std::endl;
    try
    {
        Bureaucrat alice(0, "Alice"); // Grade too high
        std::cout << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing grade too low exception ---" << std::endl;
    try
    {
        Bureaucrat charlie(151, "Charlie"); // Grade too low
        std::cout << charlie << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing increment and decrement ---" << std::endl;
    try
    {
        Bureaucrat dave(5, "Dave");
        std::cout << dave << std::endl;
        
        std::cout << "Incrementing grade..." << std::endl;
        dave.incrementGrade();
        std::cout << dave << std::endl;
        
        std::cout << "Decrementing grade..." << std::endl;
        dave.decrementGrade();
        std::cout << dave << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing increment beyond limit ---" << std::endl;
    try
    {
        Bureaucrat emma(1, "Emma");
        std::cout << emma << std::endl;
        
        std::cout << "Trying to increment beyond highest grade..." << std::endl;
        emma.incrementGrade(); // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing decrement beyond limit ---" << std::endl;
    try
    {
        Bureaucrat frank(150, "Frank");
        std::cout << frank << std::endl;
        
        std::cout << "Trying to decrement beyond lowest grade..." << std::endl;
        frank.decrementGrade(); // Should throw an exception
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}