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

	// AForm* Intern::createShrubbery(std::string target) { return new ShrubberyCreationForm(target); }
	// AForm* Intern::createRobotomy(std::string target) { return new RobotomyRequestForm(target); }
	// AForm* Intern::createPardon(std::string target) { return new PresidentialPardonForm(target); }

	class NoMatchedFormException : public std::exception
	{
		virtual const char *what() const throw();
	};

	AForm *makeForm(std::string formName, std::string formTarget);
};

#endif