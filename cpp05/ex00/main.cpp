#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("name1", 4);
	Bureaucrat min("min", 150);
	Bureaucrat max("max", 1);
	Bureaucrat copy_a(a);
	try
	{
		PRINT("");
		max.decrementGrade();
		max.incrementGrade();
		max.incrementGrade();
		max.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PRINT("");
		min.incrementGrade();
		min.decrementGrade();
		min.decrementGrade();
		min.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}