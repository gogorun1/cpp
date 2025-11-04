#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
}

Cat::Cat(Cat const &other): Animal(other._type)
{
}

Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
    PRINT("Meow~");
}

