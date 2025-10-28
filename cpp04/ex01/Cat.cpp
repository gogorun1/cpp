#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    PRINT("Cat default constructor called");
    _brain = new Brain();
}

Cat::Cat(Cat const &other): Animal(other._type)
{
    PRINT("Cat copy constructor called");
    _brain = new Brain();
}

Cat &Cat::operator=(Cat const &other)
{
    PRINT("Cat assign operator called");
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Cat::~Cat()
{
    PRINT("Cat destructor called");
    delete _brain;
}

void Cat::makeSound() const
{
    PRINT("Meow~");
}

