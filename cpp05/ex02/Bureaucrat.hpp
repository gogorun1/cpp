#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

#define PRINT(x) std::cout << x << std::endl
#define PRINTERR(x) std::cerr << x << std::endl

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	void checkGrade(int grade);

public:
	// OCF
	Bureaucrat();
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// Getters
	const std::string getName() const;
	int getGrade() const;

	// Increment & Decrement
	void incrementGrade();
	void decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Sign and execute
	void signForm(AForm &form);
	void executeForm(AForm const &form);
};

// overload insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif