#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
}

Dog::Dog(Dog const &other): Animal(other._type)
{
}

Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
    PRINT("Woof woof");
}

