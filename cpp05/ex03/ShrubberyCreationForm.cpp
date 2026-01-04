#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("shrubbery creation", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}



void ShrubberyCreationForm::action() const 
{
    std::string filename = this->getTarget() + "_shrubbery";

    std::ofstream ofs(filename.c_str());
    if (!ofs.is_open()) {
        throw std::runtime_error("Could not create file: " + filename);
    }
   
    ofs << "       /\\      " << std::endl;
    ofs << "      /\\*\\     " << std::endl;
    ofs << "     /\\*\\*\\    " << std::endl;
    
    ofs.close();
    std::cout << "Shrubbery planted successfully in " << filename << std::endl;
}