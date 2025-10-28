#include "Animal.hpp"

Animal::Animal(): _type("default")
{
    PRINT("Animal default constructor called");
}

Animal::Animal(std::string type): _type(type)
{
    PRINT("Animal constructor with parameters called");
}

Animal::Animal(Animal const &other): _type(other._type)
{
    PRINT("Animal copy constructor called");
}

Animal &Animal::operator=(Animal const &other)
{
    PRINT("Animal assign operator called");
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Animal::~Animal()
{
    PRINT("Animal destructor called");
}

void Animal::makeSound() const
{
    PRINT("Make a sound");
}

std::string Animal::getType() const
{
    return _type;
}


