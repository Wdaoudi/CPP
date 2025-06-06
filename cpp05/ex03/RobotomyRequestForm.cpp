#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45), _target("No target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("Robotomy Request Form", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::NotSign();

	if (executor.getGrade() > this->getGradeTE())
		throw AForm::GradeTooLowException();

	std::cout << "* DRILLING NOISES * Bzzz... Whirrr... Drrrrr..." << std::endl;
    
    std::srand(std::time(NULL));

    if (std::rand() % 2)
    {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << this->_target << " has failed!" << std::endl;
    }
}