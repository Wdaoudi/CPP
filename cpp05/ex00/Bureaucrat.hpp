#pragma once

#include <exception>
#include <iostream>
#include <ostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

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
	//getter
	const std::string getName() const;
	int getGrade() const;
	//modif grade function
	void incrementGrade();
	void decrementGrade();
	//nested class whom overload what from exception lib
	class GradeTooHighException : public std::exception
	{
		public: //what returns a const char*
		// to be used in the catch block
		virtual const char *what() const throw()
		{// what is the fonction which have to be overloaded 
			//on the derivate fonction
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
//outside of the class to avoid using the key word friend which is forbidden
//bcs it provides an fully access to the private member of the class 
//which lead to leak of information