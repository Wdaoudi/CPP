#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Form
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign; // same as the bureaucrat ones
	const int _gradeToExec;

  public:
	Form();
	Form(const std::string name, const int gradeTS, const int gradeTE);
	Form(const Form &copy);
	Form &operator=(const Form &other);
	~Form(void);

	const std::string getName() const;
	int getGradeTS() const;
	int getGradeTE() const;
	bool getSigned() const;

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("too high !");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("too low !");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
