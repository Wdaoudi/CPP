#include "./Form.hpp"

Form::Form(const int gradeTS, const int gradeTE)
	: _name("NoName"), _gradeToSign(150), _gradeToExec(150)
{
    _signed = 0;
	std::cout << "Form " << getName() << " is built and his grade to sign is: " << getGradeTS()
				<< " and his grade to execute is: " << getGradeTE() << std::endl;
}
Form::Form(const std::string name, const int gradeTS, const int gradeTE)
	: _name(name), _gradeToSign(gradeTS), _gradeToExec(gradeTE)
{
	if (gradeTS < HIGHEST_GRADE || gradeTE < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeTE > LOWEST_GRADE || gradeTS > LOWEST_GRADE)
		throw GradeTooLowException();
    _signed = 0;
	std::cout << "Form " << getName() << " is built and his grade to sign is: " << getGradeTS()
				<< " and his grade to execute is: " << getGradeTE() << std::endl;
}

Form::Form(const Form &copy)
:_name(copy._name),_gradeToSign(copy._gradeToSign),_gradeToExec(copy._gradeToExec)
{
    std::cout << "Form " << getName() << " is copied and his grade to sign is: "
    << getGradeTS() << " and his grade to exec is: " << getGradeTE() << std::endl;
    _signed = copy._signed;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

Form::~Form()
{}

const std::string Form::getName() const
{
    return (this->_name);
}

int Form::getGradeTE() const
{
    return (this->_gradeToExec);
}

int Form::getGradeTS() const
{
    return (this->_gradeToSign);
}

bool Form::getSigned() const
{
    return (this->_signed);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeTS())
        throw GradeTooLowException();
    else
    {
        _signed = 1;
    }
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form name:"<< form.getName() << std::endl
    << "Grade to sign: "<< form.getGradeTS() << std::endl
    << "Grade to execute: " << form.getGradeTE() <<std::endl
    << "Signed: ";
    if (form.getSigned() == 1)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return (os);
}