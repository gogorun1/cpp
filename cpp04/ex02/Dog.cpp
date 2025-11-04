#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
    _brain = new Brain();
    PRINT("Dog default constructor called");
}

Dog::Dog(Dog const &other): AAnimal(other._type)
{
    _brain = new Brain();
    PRINT("Dog copy constructor called");
}

Dog &Dog::operator=(Dog const &other)
{
    PRINT("Dog assign operator called");
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    PRINT("Dog destructor called");
}

void Dog::makeSound() const
{
    PRINT("Woof woof");
}

