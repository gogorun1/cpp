#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define PRINT(x) std::cout << x << std::endl
class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
	const std::string _target;
	void _checkGrade(int grade);

public:
	// OCF
	AForm();
	AForm(std::string Name, int Grade1, int Grade2, std::string Target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual void action() const = 0;
	virtual ~AForm();

	// Execption
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Getters
	const std::string getName() const;
	const std::string getTarget() const;
	bool getStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;

	// Member functions
	void beSigned(const Bureaucrat &rat);
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif