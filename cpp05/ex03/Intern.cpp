#include "Intern.hpp"

// OCF
Intern::Intern()
{
	PRINT("Intern is constructed");
}

Intern::Intern(const Intern &other)
{
	(void) other;
	PRINT("Intern copy constructer called");
}
Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern()
{
	PRINT("Intern is destroyed");
}

const char *Intern::NoMatchedFormException::what() const throw()
{
	return "Provided form name does not exist";
}


// function
// AForm *Intern::makeForm(std::string formName, std::string formTarget)
// {
// 	int index;
// 	std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
// 	for(index = 0; index < 3; ++index)
// 	{
// 		if (formName == form[index])
// 		{
// 			switch (index)
// 			{
// 			case 0:
// 			{
// 				return(new ShrubberyCreationForm(formTarget));
// 			}
// 			case 1:
// 			{
// 				return(new RobotomyRequestForm(formTarget));
// 			}
// 			case 2:
// 			{
// 				return(new PresidentialPardonForm(formTarget));
// 			}
// 			default:
// 				break;
// 			}
// 		}
// 	}
// 	PRINT("Intern cannot create " << formName << " because the name is unknown.");
//     return NULL;
// }

static AForm* createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (*creators[3])(std::string) = 
	{
		&createShrubbery,
		&createRobotomy,
		&createPardon
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			PRINT("Intern creates " << formName);
			return creators[i](formTarget);
		}
	}
	
	PRINTERR("Intern cannot create " << formName << " because the name is unknown.");
	throw NoMatchedFormException();
}