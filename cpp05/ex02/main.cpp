#include "Bureaucrat.hpp"
#include "Form.hpp"

// 辅助函数，用于将代码块包装在 try/catch 中，提高主函数的可读性
void executeTest(const std::string& testName, void (*testFunc)()) {
    std::cout << "\n==========================================" << std::endl;
    std::cout << ">>> " << testName << " TEST START <<<" << std::endl;
    std::cout << "==========================================" << std::endl;
    try {
        testFunc();
    } catch (const std::exception& e) {
        // 捕获测试函数中未在内部处理的标准异常
        std::cerr << "Caught unexpected exception in " << testName << ": " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Caught unknown exception in " << testName << std::endl;
    }
    std::cout << "==========================================" << std::endl;
    std::cout << ">>> " << testName << " TEST END <<<" << std::endl;
    std::cout << "==========================================" << std::endl;
}

// ----------------------------------------------------
// TEST 1: Form 构造函数异常测试
// ----------------------------------------------------
void testFormConstructionExceptions() {
    std::cout << "--- Sub-test: Too High Grade for Signing ---" << std::endl;
    try {
        // 尝试创建需要等级 0 的表格 (Too High)
        Form invalidForm1("HighGradeForm", 0, 10);
        std::cout << invalidForm1 << std::endl; // 不应执行
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "SUCCESS: Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "FAILURE: Wrong exception type caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Sub-test: Too Low Grade for Execution ---" << std::endl;
    try {
        // 尝试创建执行等级 151 的表格 (Too Low)
        Form invalidForm2("LowGradeForm", 50, 151);
        std::cout << invalidForm2 << std::endl; // 不应执行
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "SUCCESS: Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "FAILURE: Wrong exception type caught: " << e.what() << std::endl;
    }
}

// ----------------------------------------------------
// TEST 2: Bureaucrat 签署成功测试
// ----------------------------------------------------
void testSuccessfulSigning() {
    // 局长等级 50 (高等级)
    Bureaucrat highRankB("Hermes", 50); 
    // 表格要求签署等级 70 (要求低)
    Form easyForm("EasyVisa", 70, 100);

    std::cout << highRankB << std::endl;
    std::cout << easyForm << std::endl;

    // 尝试签署 (50 <= 70，成功)
    highRankB.signForm(easyForm);
    
    std::cout << "--- After Signing ---" << std::endl;
    std::cout << easyForm << std::endl; // 状态应显示 "Signed"
}

// ----------------------------------------------------
// TEST 3: Bureaucrat 签署失败测试
// ----------------------------------------------------
void testFailedSigning() {
    // 局长等级 120 (低等级)
    Bureaucrat lowRankB("Bender", 120); 
    // 表格要求签署等级 10 (要求高)
    Form hardForm("HardPermit", 10, 50);

    std::cout << lowRankB << std::endl;
    std::cout << hardForm << std::endl;

    // 尝试签署 (120 > 10，失败，Bureaucrat::signForm 应捕获 Form::GradeTooLowException)
    lowRankB.signForm(hardForm); 
    
    std::cout << "--- After Signing ---" << std::endl;
    std::cout << hardForm << std::endl; // 状态应显示 "Not Signed"
}


int main() {
    // 运行所有测试
    executeTest("FORM CONSTRUCTION EXCEPTION", testFormConstructionExceptions);
    executeTest("SUCCESSFUL SIGNING", testSuccessfulSigning);
    executeTest("FAILED SIGNING", testFailedSigning);

    // 可以在这里添加更多测试，例如重复签署已签署的表格等。

    return 0;
}