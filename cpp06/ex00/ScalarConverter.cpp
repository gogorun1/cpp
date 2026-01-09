#include "ScalarConverter.hpp"

/* ScalarConverter.cpp */
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return *this;
}


// helper
static void printImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    // Pseudo-literals
    if (literal == "nan" || literal == "nanf" || 
        literal == "inf" || literal == "inff" || 
        literal == "+inf" || literal == "+inff" || 
        literal == "-inf" || literal == "-inff") {
        std::string base = (literal.find("nan") != std::string::npos) ? "nan" : 
                           (literal.find("-inf") != std::string::npos) ? "-inf" : "+inf";
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << base << "f" << std::endl;
        std::cout << "double: " << base << std::endl;
        return;
    }

    double d;
    char* endptr;

    // char
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        d = static_cast<double>(literal[0]);
    } 
    // digits
    else {
        // no 0x
        if (literal.find("0x") != std::string::npos || literal.find("0X") != std::string::npos) {
            printImpossible();
            return;
        }

        d = std::strtod(literal.c_str(), &endptr);
        std::string remainder(endptr);
        if (!remainder.empty() && remainder != "f") {
            printImpossible();
            return;
        }
    }
    
    // print char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "impossible";
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(c))
            std::cout << "'" << c << "'";
        else
            std::cout << "Non displayable";
    }
    std::cout << std::endl;

    // print int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(d);
    }
    std::cout << std::endl;

    // print float
    std::cout << "float: " << std::fixed << std::setprecision(1) 
              << static_cast<float>(d) << "f" << std::endl;

    // print double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}