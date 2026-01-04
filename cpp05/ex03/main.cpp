#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    Intern someRandomIntern;
    AForm* form = NULL;

    std::cout << "\n=== Test 1: Create Robotomy Request ===" << std::endl;
    try {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            
            // 测试签署和执行
            Bureaucrat boss("Boss", 1);
            boss.signForm(*form);
            boss.executeForm(*form);
            
            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }

    std::cout << "\n=== Test 2: Create Shrubbery Creation ===" << std::endl;
    try {
        form = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (form) {
            std::cout << *form << std::endl;
            
            Bureaucrat clerk("Clerk", 130);
            clerk.signForm(*form);
            clerk.executeForm(*form);
            
            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }

    std::cout << "\n=== Test 3: Create Presidential Pardon ===" << std::endl;
    try {
        form = someRandomIntern.makeForm("presidential pardon", "Arthur");
        if (form) {
            std::cout << *form << std::endl;
            
            Bureaucrat president("President", 1);
            president.signForm(*form);
            president.executeForm(*form);
            
            delete form;
            form = NULL;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        if (form) {
            delete form;
            form = NULL;
        }
    }

    std::cout << "\n=== Test 4: Unknown Form Name ===" << std::endl;
    try {
        form = someRandomIntern.makeForm("coffee making", "Kitchen");
        // 如果没有抛出异常，这里会执行
        if (form) {
            std::cout << "This should not happen!" << std::endl;
            delete form;
            form = NULL;
        }
    } catch (const Intern::NoMatchedFormException& e) {
        std::cout << "Correctly caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}