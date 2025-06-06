#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
    try
    {
        // Create an intern
        std::cout << "=== Creating an Intern ===" << std::endl;
        Intern someRandomIntern;

        // Test the intern creating different forms
        std::cout << "\n=== Test : Intern creating forms ===" << std::endl;
        AForm *shrubForm = someRandomIntern.makeForm("shrubbery creation", 
                "Garden");
        AForm *robotForm = someRandomIntern.makeForm("robotomy request", 
                "Bender");
        AForm *pardonForm = someRandomIntern.makeForm("presidential pardon", 
                "Criminal");

        // Test with invalid form name
        std::cout << "\n=== Test : Invalid form name ===" << std::endl;
        try
        {
            AForm *invalidForm = someRandomIntern.makeForm("invalid form", 
                    "Target");
            (void)invalidForm;
        }
        catch (std::exception &e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Clean up allocated memory
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return (0);
}