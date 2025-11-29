#include "Bureaucrat.hpp"

void Bureaucrat::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): _name(Name),_grade(Grade)
{
	checkGrade(_grade);
	_grade = Grade;
	PRINT("Bureaucrat " << _name << " is constructed");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name + "_copy"),_grade(other._grade)
{
	PRINT("Bureaucrat " << _name << " is constructed");
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	PRINT("Bureaucrat " << _name << " is destroyed");
}