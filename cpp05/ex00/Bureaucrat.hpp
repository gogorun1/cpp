#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

#define PRINT(x) std::cout << x << std::endl;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	~Bureaucrat();
	std::string getName();
	std::string getGrade();
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Grade too low!";
		}
	};
};

Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}

#endif