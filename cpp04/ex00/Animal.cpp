#include "Animal.hpp"

Animal::Animal(): _type("default")
{
}

Animal::Animal(std::string type): _type(type)
{
}

Animal::Animal(Animal const &other): _type(other._type)
{
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Animal::~Animal()
{
}

void Animal::makeSound() const
{
    PRINT("Make a sound");
}

std::string Animal::getType() const
{
    return _type;
}


