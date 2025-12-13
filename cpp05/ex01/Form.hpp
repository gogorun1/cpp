#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

#define PRINT(x) std::cout << x << std::endl
class Bureaucrat;
class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
    void _checkGrade(int grade);
public:
    //OCF
    Form();
	Form(std::string Name, int Grade1, int Grade2);
	Form(const Form &other);
	Form &operator=(const Form &other);
    ~Form();

    //Execption
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

    //Getters
    const std::string getName() const;
    bool getStatus() const;
    int getSignGrade() const;
    int getExecGrade() const;

    //Member functions
    void beSigned(const Bureaucrat &rat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif