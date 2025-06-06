#pragma once

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

class Intern
{
  private:
  public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string name, const std::string target);

	class BadNameException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return (" doesn't match with any of the form known");
		}
	};
};