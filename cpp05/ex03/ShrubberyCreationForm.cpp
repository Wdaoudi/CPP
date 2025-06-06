#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("Shrubbery Creation Form",145,137), _target("No target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
:AForm("Shrubbery Creation Form",145,137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
:AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSigned())
        throw AForm::NotSign();
    
    if (executor.getGrade() > this->getGradeTE())
        throw AForm::GradeTooLowException();

    // creation of the file
    std::string filename = this->_target+"_shrubbery";
    std::ofstream outfile(filename.c_str()); //c_str() make the filename compatible with the std::ofstream
    // which is waiting for a const char *

    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not open file" << filename << std::endl;
        return;
    }
    outfile << "    *    " << std::endl;
    outfile << "   ***   " << std::endl;
    outfile << "  *****  " << std::endl;
    outfile << " ******* " << std::endl;
    outfile << "*********" << std::endl;
    outfile << "    |    " << std::endl;
    outfile << "    |    " << std::endl;
    outfile << "   ===   " << std::endl;

    outfile.close();
    std:: cout << "Shrubbery has been created in " << filename << std::endl;
}