#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	PRINT("* VRRRRRRR... DDDDDDzzz... drilling noises... *");

	if (std::rand() % 2)
	{
		PRINT(this->getTarget() << " has been successfully robotomized!");
	}
	else
	{
		PRINT("Robotomy failed for " << this->getTarget() << ".");
	}
}