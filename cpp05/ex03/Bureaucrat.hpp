#pragma once

#include <exception>
#include <iostream>
#include <ostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class	AForm;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	Bureaucrat();
	Bureaucrat(int const grade, const std::string name);
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);

	const std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

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

	void signForm(AForm &form);
	void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
