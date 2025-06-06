#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	: _name("NoName"),_grade(150)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException(); // overload of std::exception &e
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Member " << getName() << " is built and his grade is " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name)
	: _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Member " << getName() << " is built and his grade is " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy._name), _grade(copy._grade)
{
	std::cout << "Member " << getName() << " is copied and his grade is " << getGrade() << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	this->_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	else
		_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	else
		_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName()
		<< ",bureaucrat grade "
		<< bureaucrat.getGrade()
		<< "." << std::endl;
	return (os);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn t sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}