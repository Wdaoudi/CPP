#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating Bureaucrats ---" << std::endl;
    try
    {
        Bureaucrat highRank(1, "Director");
        Bureaucrat midRank(75, "Manager");
        Bureaucrat lowRank(150, "Intern");
        
        std::cout << "\n--- Creating Forms ---" << std::endl;
        Form easyForm("Simple Approval", 100, 100);
        Form mediumForm("Budget Request", 50, 25);
        Form hardForm("Top Secret Clearance", 5, 3);
        
        std::cout << "\n--- Displaying Forms ---" << std::endl;
        std::cout << easyForm;
        std::cout << mediumForm;
        std::cout << hardForm;
        
        std::cout << "\n--- Signing Forms (Success Cases) ---" << std::endl;
        // High rank bureaucrat can sign all forms
        highRank.signForm(easyForm);
        highRank.signForm(mediumForm);
        highRank.signForm(hardForm);
        
        std::cout << "\n--- Signing Forms (Failure Cases) ---" << std::endl;
        // Create new forms for testing failures
        Form anotherEasyForm("Another Simple Approval", 100, 100);
        Form anotherMediumForm("Another Budget Request", 50, 25);
        Form anotherHardForm("Another Top Secret Clearance", 5, 3);
        
        // Mid rank bureaucrat can only sign easy forms
        midRank.signForm(anotherEasyForm);
        midRank.signForm(anotherMediumForm); // Should fail
        midRank.signForm(anotherHardForm);   // Should fail
        
        // Low rank bureaucrat cannot sign any form
        Form yetAnotherEasyForm("Yet Another Simple Approval", 100, 100);
        lowRank.signForm(yetAnotherEasyForm); // Should fail
        
        std::cout << "\n--- Displaying Signed and Unsigned Forms ---" << std::endl;
        std::cout << easyForm;                // Should be signed
        std::cout << anotherEasyForm;         // Should be signed
        std::cout << anotherMediumForm;       // Should be unsigned
        std::cout << yetAnotherEasyForm;      // Should be unsigned
        
        std::cout << "\n--- Testing Form Grade Exceptions ---" << std::endl;
        try {
            Form invalidForm("Invalid Form", 0, 50); // Grade too high
        } catch (std::exception &e) {
            std::cout << "Exception creating form with too high grade: " << e.what() << std::endl;
        }
        
        try {
            Form invalidForm("Invalid Form", 50, 151); // Grade too low
        } catch (std::exception &e) {
            std::cout << "Exception creating form with too low grade: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}