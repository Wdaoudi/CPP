#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string nameForm[] = {"presidential pardon", "robotomy request",
		"shrubbery creation"};

	int i = 0;
	while (i < 3)
	{
		if (nameForm[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			break ;
		}
		i++;
	}
	switch (i)
	{
	case 0:
		return (new PresidentialPardonForm(target));
	case 1:
		return (new RobotomyRequestForm(target));
	case 2:
		return (new ShrubberyCreationForm(target));
    default :
        throw Intern::BadNameException();
	};
    return (NULL);
}