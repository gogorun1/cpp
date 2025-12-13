#include "Bureaucrat.hpp"

// Helper functions
void Bureaucrat::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

// OCF
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	PRINT("Bureaucrat " << _name << " is constructed");
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : _name(Name), _grade(Grade)
{
	checkGrade(_grade);
	PRINT("Bureaucrat " << _name << " is constructed");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name + "_copy"), _grade(other._grade)
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

// Getters
const std::string Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

// Increment & Decrement
void Bureaucrat::incrementGrade()
{
	PRINT(*this);
	checkGrade(_grade - 1);
	_grade -= 1;
	PRINT("Increment grade of " << _name << ", now the grade is " << _grade);
}
void Bureaucrat::decrementGrade()
{
	PRINT(*this);
	checkGrade(_grade + 1);
	_grade += 1;
	PRINT("Decrement grade of " << _name << ", now the grade is " << _grade);
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

// overload insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

// new added function
void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		PRINT(_name << " Signed " << form.getName());
	} catch(const Form::GradeTooLowException &e) {
		PRINT(_name << " couldn't sign " << form.getName() << " because " <<  e.what());
	}
}