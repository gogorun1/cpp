#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

void executeTest(const std::string &testName, void (*testFunc)())
{
	std::cout << "\n==========================================" << std::endl;
	std::cout << ">>> " << testName << " TEST START <<<" << std::endl;
	std::cout << "==========================================" << std::endl;
	try
	{
		testFunc();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught unexpected standard exception in " << testName << ": " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Caught unknown exception in " << testName << std::endl;
	}
	std::cout << "==========================================" << std::endl;
	std::cout << ">>> " << testName << " TEST END <<<" << std::endl;
	std::cout << "==========================================" << std::endl;
}

// ----------------------------------------------------
// TEST 1: ShrubberyCreationForm
// ----------------------------------------------------
void testShrubbery()
{
	// Shrubbery: Sign 145, Exec 137
	Bureaucrat lowRankB("Bender", 140); // able to sign(140 <= 145)，not able to execute (140 > 137)
	Bureaucrat highRankB("Fry", 130);	// sign and execute

	try
	{
		ShrubberyCreationForm form1("Home");
		lowRankB.signForm(form1);
		std::cout << form1 << std::endl;

		lowRankB.executeForm(form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception in test 1.1: " << e.what() << std::endl;
	}

	std::cout << "\n--- Sub-test: Successful Execution (Fry) ---" << std::endl;

	try
	{
		ShrubberyCreationForm form2("Garden");
		highRankB.signForm(form2);
		highRankB.executeForm(form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception in test 1.2: " << e.what() << std::endl;
	}
}

// // ----------------------------------------------------
// // TEST 2: RobotomyRequestForm (随机性与未签署)
// // ----------------------------------------------------
// void testRobotomy()
// {
// 	// Robotomy: Sign 72, Exec 45
// 	Bureaucrat mediumRankB("Hermes", 50); // 可签署 (50 <= 72)，不可执行 (50 > 45)
// 	Bureaucrat topRankB("Zoidberg", 1);	  // 可签署，可执行

// 	// 1. 测试未签署执行失败 (Hermes)
// 	try
// 	{
// 		RobotomyRequestForm form3("Professor");
// 		std::cout << form3 << std::endl;
// 		mediumRankB.executeForm(form3); // 执行失败：未签署
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception in test 2.1: " << e.what() << std::endl;
// 	}

// 	std::cout << "\n--- Sub-test: Execution Attempts (Zoidberg) ---" << std::endl;
// 	// 2. 测试多次执行 (Zoidberg) - 验证随机性
// 	try
// 	{
// 		RobotomyRequestForm form4("Leela");
// 		topRankB.signForm(form4);

// 		// 尝试多次执行，应看到成功的钻孔声和失败的钻孔声
// 		for (int i = 0; i < 4; ++i)
// 		{
// 			topRankB.executeForm(form4);
// 		}
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception in test 2.2: " << e.what() << std::endl;
// 	}
// }

// // ----------------------------------------------------
// // TEST 3: PresidentialPardonForm (高级执行要求)
// // ----------------------------------------------------
// void testPardon()
// {
// 	// Pardon: Sign 25, Exec 5
// 	Bureaucrat lowRankB("Amy", 30);	   // 可签署 (30 <= 25 失败)，不可执行
// 	Bureaucrat highRankB("Kif", 10);   // 可签署 (10 <= 25 成功)，不可执行 (10 > 5)
// 	Bureaucrat president("Zaphod", 1); // 可签署，可执行

// 	// 1. 测试签署失败 (Amy)
// 	try
// 	{
// 		PresidentialPardonForm form5("Nixon");
// 		lowRankB.signForm(form5); // 签署失败：等级不足
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception in test 3.1: " << e.what() << std::endl;
// 	}

// 	std::cout << "\n--- Sub-test: Successful Execution (Zaphod) ---" << std::endl;
// 	// 2. 测试成功执行 (Zaphod)
// 	try
// 	{
// 		PresidentialPardonForm form6("Bender");
// 		president.signForm(form6);
// 		president.executeForm(form6); // 成功执行
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Exception in test 3.2: " << e.what() << std::endl;
// 	}
// }

int main()
{
	// 初始化随机数种子，用于 RobotomyRequestForm
	std::srand(std::time(0));

	executeTest("SHRUBBERY FORM TEST", testShrubbery);
	// executeTest("ROBOTOMY FORM TEST", testRobotomy);
	// executeTest("PRESIDENTIAL PARDON TEST", testPardon);

	return 0;
}