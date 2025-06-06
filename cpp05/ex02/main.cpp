#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        // Create bureaucrats with different grades
        std::cout << "=== Creating Bureaucrats ===" << std::endl;
        Bureaucrat highRank(5, "Director");
        Bureaucrat midRank(45, "Manager");
        Bureaucrat lowRank(140, "Intern");
        
        std::cout << "\n=== Creating Forms ===" << std::endl;
        // Create the different types of forms
        ShrubberyCreationForm shrubForm("garden");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Criminal");
        
        std::cout << "\n=== Test 1: Signing Forms ===" << std::endl;
        // High rank can sign all forms
        highRank.signForm(shrubForm);
        highRank.signForm(robotForm);
        highRank.signForm(pardonForm);
        
        std::cout << "\n=== Test 2: Executing Forms with proper authorization ===" << std::endl;
        // High rank can execute all forms
        highRank.executeForm(shrubForm);
        highRank.executeForm(robotForm);
        highRank.executeForm(pardonForm);
        
        std::cout << "\n=== Test 3: Creating new forms for permission tests ===" << std::endl;
        // Create new forms for tests
        ShrubberyCreationForm shrubForm2("park");
        RobotomyRequestForm robotForm2("R2D2");
        PresidentialPardonForm pardonForm2("Prisoner");
        
        // Sign all forms for the next tests
        highRank.signForm(shrubForm2);
        highRank.signForm(robotForm2);
        highRank.signForm(pardonForm2);
        
        std::cout << "\n=== Test 4: Execute forms with mid-rank bureaucrat ===" << std::endl;
        // Mid rank can execute only some forms
        midRank.executeForm(shrubForm2);   // Should work
        midRank.executeForm(robotForm2);   // Should work
        midRank.executeForm(pardonForm2);  // Should fail (grade too low)
        
        std::cout << "\n=== Test 5: Execute forms with low-rank bureaucrat ===" << std::endl;
        // Low rank can only execute Shrubbery forms
        lowRank.executeForm(shrubForm2);   // Should work
        lowRank.executeForm(robotForm2);   // Should fail (grade too low)
        lowRank.executeForm(pardonForm2);  // Should fail (grade too low)
        
        std::cout << "\n=== Test 6: Try to execute unsigned forms ===" << std::endl;
        // Create new unsigned forms
        ShrubberyCreationForm unsignedShrub("forest");
        RobotomyRequestForm unsignedRobot("C3PO");
        PresidentialPardonForm unsignedPardon("Innocent");
        
        // Try to execute unsigned forms
        highRank.executeForm(unsignedShrub);  // Should fail (not signed)
        highRank.executeForm(unsignedRobot);  // Should fail (not signed)
        highRank.executeForm(unsignedPardon); // Should fail (not signed)
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}