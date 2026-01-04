#include "AForm.hpp"

void AForm::_checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

// OCF
AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(std::string Name, int Grade1, int Grade2, std::string Target) : _name(Name), _isSigned(false), _signGrade(Grade1), _execGrade(Grade2), _target(Target)
{
	_checkGrade(_signGrade);
	_checkGrade(_execGrade);
	PRINT(Name << " is constructed");
}

AForm::AForm(const AForm &other) : _name(other._name + "_copy"), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	_checkGrade(_signGrade);
	_checkGrade(_execGrade);
	PRINT("Copy constructor is called.");
}

AForm &AForm::operator=(const AForm &other)
{
	(void)other;
	PRINT("Copy assignment is diabled because all variables are const.");
	return *this;
}

AForm::~AForm()
{
}

// Exception
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "This form is not signed!";
}

// Getters
const std::string AForm::getName() const
{
	return (_name);
}

const std::string AForm::getTarget() const
{
	return (_target);
}

bool AForm::getStatus() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

// Member functions
void AForm::beSigned(const Bureaucrat &rat)
{
    if (_isSigned) {
        PRINT("Form " << _name << " is already signed!");
        return;
    }
    
    if (rat.getGrade() <= this->getSignGrade())
        _isSigned = true;
    else
        throw(GradeTooLowException());
}

// overload insertion
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName()
	   << ", Status: " << (form.getStatus() ? "Signed" : "Not Signed")
	   << ", Required Grade to Sign: " << form.getSignGrade()
	   << ", Required Grade to Execute: " << form.getExecGrade();
	return os;
}

// execute check
void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _execGrade)
	{
		throw GradeTooLowException();
	}
	this->action();
}