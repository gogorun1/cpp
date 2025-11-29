#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

#define PRINT(x) std::cout << x << std::endl

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	void checkGrade(int grade);
public:
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

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



#endif