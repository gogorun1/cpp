#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other._type)
{
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    if (this != &other)
    {
       this->_type = other._type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
    PRINT("Meow~");
}

