#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        PRINT("Error: Usage: ./convert [literal]");
        return 0;
    }
    std::string literal;
    literal = argv[1];
    ScalarConverter::convert(literal);
    return 0;
}