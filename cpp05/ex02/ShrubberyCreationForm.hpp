#ifndef SCF_H
#define SCF_H

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string &target);
	~ShrubberyCreationForm();

// OCF
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

// Pure virtual
	virtual void action() const;
};

#endif