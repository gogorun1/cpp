#ifndef RRF_H
#define RRF_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib> // For rand()

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();

// OCF
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

// Pure virtual
	virtual void action() const;
};

#endif