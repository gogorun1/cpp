#include "Form.hpp"

void Form::_checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

// OCF
Form::Form():_name("Default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(std::string Name, int Grade1, int Grade2):_name(Name), _isSigned(false), _signGrade(Grade1), _execGrade(Grade2)
{
    _checkGrade(_signGrade);
    _checkGrade(_execGrade);
    PRINT(Name << " is constructed");
}

Form::Form(const Form &other):_name(other._name + "_copy"), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    _checkGrade(_signGrade);
    _checkGrade(_execGrade);
    PRINT("Copy constructor is called.");
}

Form &Form::operator=(const Form &other)
{
    (void)other;
    PRINT("Copy assignment is diabled because all variables are const.");
    return *this;
}

Form::~Form()
{
}

// Exception
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

// Getters
const std::string Form::getName() const
{
    return(_name);
}

bool Form::getStatus() const
{
    return(_isSigned);
}

int Form::getSignGrade() const
{
    return(_signGrade);
}

int Form::getExecGrade() const
{
    return(_execGrade);
}

// Member functions
void Form::beSigned(const Bureaucrat &rat)
{
    if (rat.getGrade() <= this->getSignGrade())
        _isSigned = true;
    else 
        throw(GradeTooLowException());
}

// overload insertion
std::ostream& operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Status: " << (form.getStatus() ? "Signed" : "Not Signed")
       << ", Required Grade to Sign: " << form.getSignGrade()
       << ", Required Grade to Execute: " << form.getExecGrade();
    return os;
}