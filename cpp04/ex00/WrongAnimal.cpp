#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("default")
{
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
}

WrongAnimal::WrongAnimal(WrongAnimal const &other): _type(other._type)
{
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
}

void WrongAnimal::makeSound() const
{
    PRINT("Make a wrong animal sound");
}

std::string WrongAnimal::getType() const
{
    return _type;
}


