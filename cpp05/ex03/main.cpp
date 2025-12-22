#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* unknown;

    // 1. 测试正常创建
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl;
        delete rrf; // 别忘了释放内存
    }

    // 2. 测试另一种表单
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf) {
        delete scf;
    }

    // 3. 测试错误名称
    unknown = someRandomIntern.makeForm("coffee making", "Kitchen");
    if (!unknown) {
        std::cout << "Correctly handled unknown form name." << std::endl;
    }

    return 0;
}