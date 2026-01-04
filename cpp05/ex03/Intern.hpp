#ifndef Intern_H
#define Intern_H

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define PRINT(x) std::cout << x << std::endl
#define PRINTERR(x) std::cerr << x << std::endl

class AForm;

class Intern
{
private:

public:
	// OCF
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	class NoMatchedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};	


	AForm *makeForm(std::string formName, std::string formTarget);
};

#endif