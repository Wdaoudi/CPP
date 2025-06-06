#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class AForm
{
  private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign; // same as the bureaucrat ones
	const int _gradeToExec;

  public:
	AForm();
	AForm(const std::string name, const int gradeTS, const int gradeTE);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	const std::string getName() const;
	int getGradeTS() const;
	int getGradeTE() const;
	bool getSigned() const;

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;//ajout de la fonction

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
	
	class NotSign : public std::exception
	{
		public :
		virtual const char *what() const throw()
		{
			return ("Form not signed !");
		}
	};
};
std::ostream &operator<<(std::ostream &os, const AForm &Aform);